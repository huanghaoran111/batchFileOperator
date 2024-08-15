#include <XFileCrypt/xfile_crypt.h>
#include <XCrypt/xcrypt.h>
#include <XCryptTask/xcrypt_task.h>
#include <XIOStream/xiostream.h>
#include <XWriteTask/xwrite_task.h>
#include <XReadTask/xread_task.h>


int main()
{
    auto xfc = std::make_shared<XFileCrypt>();
    xfc->Start("./assets/testTxtFile/test.txt", "./assets/testTxtFile/test_end.txt", "12345678", true);
    xfc->Wait();

    auto xfd = std::make_shared<XFileCrypt>();
    xfd->Start("./assets/testTxtFile/test_end.txt", "./assets/testTxtFile/test_dec.txt", "12345678", false);
    xfd->Wait();
    
}