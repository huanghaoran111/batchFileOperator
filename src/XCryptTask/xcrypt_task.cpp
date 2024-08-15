#include "xcrypt_task.h"
#include <XCrypt/xcrypt.h>
#include <iostream>
#include <thread>
#include <memory>
#include <XData/xdata.h>

/**
 * @todo 初始化加解密密钥
*/
void XCryptTask::Init(std::string passwd)
{
    enc_ = std::make_shared<XCrypt>();
    enc_->Init(passwd);
}

void XCryptTask::Main()
{
    // std::cout << "begin XCryptTask::Main()" << std::endl;
    while(!is_exit_)
    {
        auto data = PopFront();
        if(!data)
        {
            std::this_thread::sleep_for(std::literals::chrono_literals::operator""ms(10));
            continue;
        }
        auto out = XData::Make(mem_pool_);
        int outsize = data->size() + enc_->GetPadding(data->size());
        out->New(outsize);
        int data_size = 0; 
        bool is_end = data->end();
        if(is_encrypt_)
        {
            data_size = enc_->Encrypt((char*)data->data(), data->size(), (char*)out->data(), is_end);
        }
        else
        {
            data_size = enc_->Decrypt((char*)data->data(), data->size(), (char*)out->data(), is_end);
        }
        out->set_size(data_size);
        out->set_end(data->end());
        if(next_)
        {
            next_->PushBack(out);
        }
        if(data->end())
        {
            break;
        }
        // std::cout << "<" <<out->size() << ">" << std::flush;
    }
    // std::cout << "end XCryptTask::Main()" << std::endl;
} 