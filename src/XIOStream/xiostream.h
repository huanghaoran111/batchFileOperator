#pragma once
#include <thread>
#include <memory>
#include <memory_resource>
#include <list>

class XData;
class XIOStream
{
public:

    /**
     * @todo 线程启动
    */
    void Start();

    /**
     * @todo 等待线程退出
    */
    void Wait();

    /**
     * @todo 线程退出需要用Wait等待
    */
    void Stop() { is_exit_ = true; }

    /**
     * @todo 设置线程池
     * 
     * 
    */
    void set_mem_pool(std::shared_ptr<std::pmr::memory_resource> p) { mem_pool_ = p; }

    /**
     * @todo 设置责任链的下一个节点
    */
    void set_next(std::shared_ptr<XIOStream> next) { next_ = next; }

    /**
     * @todo 给对象传递数据，线程安全
    */
    void PushBack(std::shared_ptr<XData> data);

    /**
     * @todo 弹出数据
    */
    std::shared_ptr<XData> PopFront();

protected:
    /**
     * @todo 线程入口
    */
    virtual void Main() {}

    bool is_exit_ = false;

    long long data_byte_ = 0;       // 所有要处理数据的字节数

    std::shared_ptr<std::pmr::memory_resource> mem_pool_;

    /**
     * @todo 责任链代码
    */
    std::shared_ptr<XIOStream> next_;

private:
    std::thread th_;
    std::mutex mux_;
    std::list<std::shared_ptr<XData>> datas_;
};