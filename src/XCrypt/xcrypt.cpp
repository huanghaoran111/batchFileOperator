#include "xcrypt.h"
#include <string.h>
#include <iostream>

/**
 * @todo 获取需要填充的数据字节数
*/
int XCrypt::GetPadding(int datasize)
{
    const int block_size = sizeof(const_DES_cblock);
    int padding = block_size - datasize % block_size;
    if(padding == 0) padding = block_size;
    return padding;
}

/**
 * @todo 初始化密钥，DES加密算法，密钥最多8位，多余丢弃，不足补0
 * 
 * @param passwd 密钥
 * @return 初始化是否成功
*/
bool XCrypt::Init(std::string passwd)
{
    const_DES_cblock key = { 0 };   // 不足补0
    int key_size = passwd.size();
    if(key_size > sizeof(key))  // 多余丢弃
    {
        key_size = sizeof(key);
    }
    memcpy(key, passwd.c_str(), key_size);
    DES_set_key(&key, &key_sch_);
    return true;
}

/**
 * @todo 加密数据，结尾填充补充的大小，加密数据如果不是8，16的倍数
 * 
 * @param in_data 输入数据
 * @param in_size 输入大小
 * @param out_data 输出数据
 * @param is_end 是否到加密结尾
 * @return 返回加密后的数据，有可能大于输入，添加补充
*/
int XCrypt::Encrypt(const char* in_data, int in_size, char* out_data, bool is_end)
{
    if(!in_data || in_size <= 0 || !out_data) return 0;
    int write_size = 0;

    const_DES_cblock in = { 0 };    // 输入数据
    DES_cblock out = { 0 };         // 输出
    const int block_size = sizeof(const_DES_cblock);
    int data_size = 0;
    int padding = block_size - in_size % block_size;
    for(int i = 0; i < in_size; i += block_size)
    {
        if(in_size - i < block_size)
        {
            data_size = in_size - i;
        }
        else
        {
            data_size = block_size;
        }

        // 复制数据源
        memcpy(in, in_data + write_size, block_size);
        
        // 填充 补充的数据大小
        if(is_end && i + block_size >= in_size) // 处理最后一块数据
        {
            if(padding == block_size)
            {
                DES_ecb_encrypt(&in, &out, &key_sch_, DES_ENCRYPT);
                memcpy(out_data + write_size, &out, block_size);
                write_size += block_size;
                memset(in, padding, sizeof(in));    // 填充8
            }
            else
            {
                memset(in + in_size % block_size, padding, padding);
            }
        }
        // 
        // 加密数据
        DES_ecb_encrypt(&in, &out, &key_sch_, DES_ENCRYPT);

        
        memcpy(out_data + write_size, &out, block_size);
        write_size += block_size;
    }

    return write_size;
}


/**
 * @todo 解密数据，结尾去掉填充大小
 * 
 * @param in_data 输入数据
 * @param in_size 输入大小
 * @param out_data 输出数据
 * @param is_end 是否到加密结尾
 * @return 返回解密后的数据，有可能小于输入，去掉补充
*/
int XCrypt::Decrypt(const char* in_data, int in_size, char* out_data, bool is_end)
{
    if(!in_data || in_size <= 0 || !out_data) return 0;
    int write_size = 0;
    const_DES_cblock in = { 0 };    // 输入数据
    DES_cblock out = { 0 };         // 输出
    const int block_size = sizeof(const_DES_cblock);
    int data_size = 0;
    for(int i = 0; i < in_size; i += block_size)
    {
        memcpy(in, in_data + write_size, block_size);

        // 解密
        DES_ecb_encrypt(&in, &out, &key_sch_, DES_DECRYPT);
        data_size = block_size;
        // 处理结尾填充
        if(is_end && in_size - i <= block_size)
        {
            data_size = block_size - out[7];
            if(data_size == 0)
            {
                break;
            }
            else if(data_size < 0)
            {
                std::cerr << "Decrypt failed! padding size error!" << std::endl;
                break;
            }
        }
        memcpy(out_data + write_size, &out, data_size);
        write_size += data_size;
    }
    return write_size;
}
