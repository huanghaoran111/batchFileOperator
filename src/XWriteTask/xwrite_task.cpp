#include "xwrite_task.h"
#include <iostream>
#include <XData/xdata.h>

using namespace std;

bool XWriteTask::Init(std::string filename)
{
    ofs_.open(filename, std::ios::binary);
    if(!ofs_)
    {
        std::cerr << "文件打开失败! " << filename << std::endl; 
        return false;
    }
    // std::cout << filename << " open success! " << std::endl;
    return true;
}

void XWriteTask::Main()
{
    while(!is_exit_)
    {
        auto data = PopFront();
        if(!data)
        {
            std::this_thread::sleep_for(10ms);
            continue;
        }
        ofs_.write((char*)data->data(), data->size());
        if(data->end())
            break;
        
    }
    ofs_.close();
}