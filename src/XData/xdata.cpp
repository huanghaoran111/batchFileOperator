#include "xdata.h"
#include <iostream>

/**
 * @todo 创建XData智能指针对象
 * 
 * @param pool 使用的内存池
*/
std::shared_ptr<XData> XData::Make(std::shared_ptr<std::pmr::memory_resource> pool)
{
    std::shared_ptr<XData> ptr(new XData);
    ptr->mem_pool_ = pool;
    return ptr;
}

/**
 * @todo 创建空间
 * 
 * @param mem_size 占用空间字节数
*/
void* XData::New(long long mem_size)
{
    if(mem_size <= 0)
    {
        std::cerr << "XData::New failed! mem_size <= 0" << std::endl;
        return nullptr;
    }
    if(!mem_pool_) return nullptr;
    data_ = mem_pool_->allocate(mem_size);
    this->mem_size_ = mem_size;
    this->size_ = mem_size;
    // std::cout << "+" << std::flush;
    return data_;
}


XData::~XData()
{
    if(!data_ || !mem_pool_) return;
    mem_pool_->deallocate(data_, mem_size_);
    data_ = nullptr;
    mem_size_ = 0;
    size_ = 0;
    // std::cout << "-" << std::flush;
}