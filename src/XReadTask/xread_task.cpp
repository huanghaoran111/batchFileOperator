#include "xread_task.h"
#include <iostream>
#include <XData/xdata.h>
/**
 * @todo 初始化读取线程，获取文件大小
 * 
 * @param filename 文件路径
 * @return 
*/
bool XReadTask::Init(std::string filename)
{
    if(filename.empty()) return false;
    ifs_.open(filename, std::ios::binary);      // 二进制打开
    if(!ifs_)
    {
        std::cerr << "open file " << filename << " failed!" << std::endl;
    }
    std::cout << filename << " open success!" << std::endl;
    ifs_.seekg(0, std::ios::end);
    data_byte_ = ifs_.tellg();
    ifs_.seekg(0, std::ios::beg);
    // std::cout << " file size " << data_byte_ << std::endl;
    return true;
}

/**
 * @todo 线程入口
*/
void XReadTask::Main()
{
    // std::cout << "begin thread XReadTask::Main" << std::endl;
    while(!is_exit_)
    {
        if(ifs_.eof()) break;
        /*
        char buf[10240] = { 0 };
        ifs_.read(buf, sizeof(buf));
        std::cout << "[" << ifs_.gcount() << "]" << std::flush;
        //*/
        // 创建内存池空间管理对象
        auto data = XData::Make(this->mem_pool_);
        int data_size = 1024;
        
        // 申请空间
        void* buf = data->New(data_size);

        // 读取文件
        ifs_.read((char*)buf, data_size);

        if(ifs_.gcount() <= 0) break;
        data->set_size(ifs_.gcount());
        if(ifs_.eof())
        {
            data->set_end(true);
        }
        // std::cout << "[" << ifs_.gcount() << "]" << std::flush;

        if(next_)
        {
            next_->PushBack(data);
        }
    }
    ifs_.close();
    // std::cout << "end thread XReadTask::Main" << std::endl;
}