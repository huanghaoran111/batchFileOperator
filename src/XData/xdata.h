#pragma once

#include <memory>
#include <memory_resource>


class XData
{
public:

    /**
     * @todo 创建空间
     * 
     * @param mem_size 占用空间字节数
    */
    void *New(long long mem_size);

    long long size() { return size_; }

    void* data() { return data_; }

    bool end() { return end_;}

    void set_end(bool e) { end_ = e; }

    /**
     * @todo 设置实际数据字节数
     * 
     * @param s 设定的字节数
    */
    void set_size(long long s) { size_ = s; } 

    /**
     * @todo 创建XData智能指针对象
     * 
     * @param pool 使用的内存池
    */
    static std::shared_ptr<XData> Make(std::shared_ptr<std::pmr::memory_resource> pool);

    ~XData();
private:
    bool end_ = false; 
    void* data_ = nullptr;
    long long size_ = 0;            // 数据大小
    long long mem_size_ = 0;        // 占用空间字节数
    std::shared_ptr<std::pmr::memory_resource> mem_pool_;
    XData() {}      // 不能用户自己创建
};