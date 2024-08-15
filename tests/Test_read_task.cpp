#include <XReadTask/xread_task.h>

int main()
{
    XReadTask rt;
    rt.Init("./assets/img/test.png");
    rt.Start();
    rt.Wait();
}