#pragma once
#include <XIOStream/xiostream.h>

class XCrypt;

/**
 * @struct 加密线程结构体
*/
class XCryptTask : public XIOStream
{
public:
    /**
     * @todo 初始化加解密密钥
    */
    void Init(std::string passwd);

    void set_is_encrypt(bool ise) { is_encrypt_ = ise; }
private:
    void Main(); 
    std::shared_ptr<XCrypt> enc_;
    bool is_encrypt_ = true;
};