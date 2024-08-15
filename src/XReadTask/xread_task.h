#pragma once
#include <XIOStream/xiostream.h>
#include <string>
#include <fstream>

class XReadTask : public XIOStream
{
public:
    /**
     * @todo 初始化读取线程，获取文件大小
     * 
     * @param filename 文件路径
     * @return 
    */
    bool Init(std::string filename);
private:
    /**
     * @todo 线程入口
    */
    void Main();
    std::ifstream ifs_; // 读取文件
};