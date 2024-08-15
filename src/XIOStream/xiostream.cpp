#include "xiostream.h"
#include <XData/xdata.h>
#include <mutex>
/**
 * @todo 线程启动
*/
void XIOStream::Start()
{
    th_ = std::thread(&XIOStream::Main, this);
}

/**
 * @todo 给对象传递数据，线程安全
*/
void XIOStream::PushBack(std::shared_ptr<XData> data)
{
    std::unique_lock<std::mutex> lock(mux_);
    datas_.push_back(data);
    // 考虑最大列表
}

/**
 * @todo 弹出数据
*/
std::shared_ptr<XData> XIOStream::PopFront()
{
    std::unique_lock<std::mutex> lock(mux_);
    if(datas_.empty()) return nullptr;
    auto re = datas_.front();
    datas_.pop_front();
    return re;
}

/**
 * @todo 等待线程退出
*/
void XIOStream::Wait()
{
    if(th_.joinable())
        th_.join();
    
}