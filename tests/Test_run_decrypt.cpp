
#include <memory>
#include <memory_resource>

#include <XCrypt/xcrypt.h>
#include <XCryptTask/xcrypt_task.h>
#include <XIOStream/xiostream.h>
#include <XWriteTask/xwrite_task.h>
#include <XReadTask/xread_task.h>

int main()
{
    // 数据加密
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
        ct->set_is_encrypt(true);
        rt->set_next(ct);

        auto wt = std::make_shared<XWriteTask>();
        wt->set_mem_pool(mp);
        wt->Init("./assets/img/test_out.png");

        ct->set_next(wt);

        rt->Start();
        ct->Start();
        wt->Start();

        rt->Wait();
        ct->Wait();
        wt->Wait();
    }
    // 数据解密
    {
        std::string passwd = "12345678";
        std::shared_ptr<std::pmr::memory_resource> mp(new std::pmr::synchronized_pool_resource());
        auto rt = std::make_shared<XReadTask>();
        rt->Init("./assets/img/test_out.png");
        rt->set_mem_pool(mp);

        auto ct = std::make_shared<XCryptTask>();
        ct->set_mem_pool(mp);
        ct->Init(passwd);
        ct->set_is_encrypt(false);
        rt->set_next(ct);

        auto wt = std::make_shared<XWriteTask>();
        wt->set_mem_pool(mp);
        wt->Init("./assets/img/test_dec.png");

        ct->set_next(wt);

        rt->Start();
        ct->Start();
        wt->Start();

        rt->Wait();
        ct->Wait();
        wt->Wait();
    }
}