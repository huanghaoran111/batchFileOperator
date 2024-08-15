#include "xfile_crypt.h"
#include <XWriteTask/xwrite_task.h>
#include <XReadTask/xread_task.h>
#include <XCryptTask/xcrypt_task.h>

#include <iostream>

using namespace std;

bool XFileCrypt::Start(std::string infile, std::string outfile, std::string passwd, bool is_encrypt)
{
    std::shared_ptr<std::pmr::memory_resource> mp(new std::pmr::synchronized_pool_resource());
    // XReadTask rt;
    rt_ = std::make_shared<XReadTask>();
    rt_->Init(infile);
    rt_->set_mem_pool(mp);
    ct_ = std::make_shared<XCryptTask>();
    ct_->set_mem_pool(mp);
    ct_->Init(passwd);
    ct_->set_is_encrypt(is_encrypt);
    rt_->set_next(ct_);

    wt_ = std::make_shared<XWriteTask>();
    wt_->set_mem_pool(mp);
    wt_->Init(outfile);

    ct_->set_next(wt_);

    rt_->Start();
    ct_->Start();
    wt_->Start();
    return true;
}

void XFileCrypt::Wait()
{
    if(rt_)
        rt_->Wait();
    if(ct_)
        ct_->Wait();
    if(wt_)
        wt_->Wait();
}