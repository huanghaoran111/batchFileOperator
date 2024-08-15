#pragma once
#include <string>
#include <openssl/des.h>

class XCrypt
{
public: 
    /**
     * @todo 初始化密钥，DES加密算法，密钥最多8位，多余丢弃，不足补0
     * 
     * @param passwd 密钥
     * @return 初始化是否成功
    */
    bool Init(std::string passwd);

    /**
     * @todo 加密数据，结尾填充补充的大小，加密数据如果不是8，16的倍数
     * 
     * @param in_data 输入数据
     * @param in_size 输入大小
     * @param out_data 输出数据
     * @param is_end 是否到加密结尾
     * @return 返回加密后的数据，有可能大于输入，添加补充
    */
    int Encrypt(const char* in_data, int in_size, char* out_data, bool is_end = false);

    /**
     * @todo 解密数据，结尾去掉填充大小
     * 
     * @param in_data 输入数据
     * @param in_size 输入大小
     * @param out_data 输出数据
     * @param is_end 是否到加密结尾
     * @return 返回解密后的数据，有可能小于输入，去掉补充
    */
    int Decrypt(const char* in_data, int in_size, char* out_data, bool is_end = false);

    /**
     * @todo 获取需要填充的数据字节数
    */
    int GetPadding(int datasize);
    
private:
    DES_key_schedule key_sch_;      // 存储密钥

};