#include <XFileCrypt/xfile_crypt.h>
#include <XWriteTask/xwrite_task.h>
#include <XReadTask/xread_task.h>
#include <XCrypt/xcrypt.h>

#include <iostream>
#include <filesystem>
#include <memory>
#include <memory_resource>
#include <list>

int main(int argc, char* argv[])
{
    // 加密文件指令: crypt_file 输入文件夹 输出文件夹 密码
    // 解密文件指令: ceypt_file 输入文件夹 输出文件夹 密码 -d
    if(argc < 4)
    {
        std::cerr << "para error" << std::endl;
        return -1;
    }
    std::string in_file = argv[1];      // 输入文件夹
    std::string out_file = argv[2];     // 输出文件夹
    std::string password = argv[3];     // 密码
    bool is_encrypt = true;
    if(argc > 4)
    {
        is_encrypt = false;
    }

    // 创建输出文件夹
    std::filesystem::create_directories(out_file);
    //if(is_encrypt)
    
    std::list<std::shared_ptr<XFileCrypt>> fes;
    for(auto &p : std::filesystem::directory_iterator(in_file))     // 遍历输入目录
    {
        if(!p.is_regular_file()) continue;  // 值处理为只处理文件
        auto fe = std::make_shared<XFileCrypt>();
        fe->Start(p.path().string()
            , out_file + "/" + p.path().filename().string()
            , password
            , is_encrypt
        );
        fes.push_back(fe);
    }
    for(auto fe : fes)
    {
        fe->Wait();
    }
    return 0;
}