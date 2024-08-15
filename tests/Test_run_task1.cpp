#include <XReadTask/xread_task.h>
#include <XCryptTask/xcrypt_task.h>
#include <XCrypt/xcrypt.h>
#include <memory>
#include <memory_resource>

#include <iostream>

int main()
{
    std::string passwd = "12345678";
    std::shared_ptr<std::pmr::memory_resource> mp(new std::pmr::synchronized_pool_resource());
    // XReadTask rt;
    auto rt = std::make_shared<XReadTask>();
    rt->Init("./assets/img/test.png");
    rt->set_mem_pool(mp);
    auto ct = std::make_shared<XCryptTask>();
    ct->set_mem_pool(mp);
    ct->Init(passwd);
    rt->set_next(ct);

    rt->Start();
    ct->Start();

    rt->Wait();
    ct->Wait();
}