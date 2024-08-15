#include <XReadTask/xread_task.h>
#include <memory>
#include <memory_resource>

int main()
{
    std::shared_ptr<std::pmr::memory_resource> mp(new std::pmr::synchronized_pool_resource());
    XReadTask rt;
    rt.Init("./assets/img/test.png");
    rt.set_mem_pool(mp);
    rt.Start();
    rt.Wait();

}