#include <iostream>
#include <XCrypt/xcrypt.h>

int main()
{
    std::cout << "目录下文件批量加密" << std::endl;
    XCrypt crypt;
    crypt.Init("12345678");
    char out[1024] = { 0 };
    int en_size = crypt.Encrypt("abcdefgh", 8, out, true);
    std::cout << "en_size = " << en_size << std::endl;
    std::cout << out << std::endl;
    char de_out[1024] = { 0 };
    int de_size = crypt.Decrypt(out, en_size, de_out, true);
    std::cout << de_size << ": de_out = " << de_out << std::endl; 
    
    return 0;
}