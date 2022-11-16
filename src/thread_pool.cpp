#include "thread_pool.h"
#include <atomic>

namespace yuki_new_features__thread_test
{
    void promiseFutureTest()
    {
        auto f = [](std::promise<std::string>& a_p, std::mutex& a_m){
            std::lock_guard l(a_m);
            std::cout << "promiseTest" << std::endl;
            a_p.set_value("child thread: promiseTest");
        };
        std::mutex m;
        std::promise<std::string> p;
        std::future<std::string> futu = p.get_future();

        std::thread t(f, std::ref(p), std::ref(m));
        t.join();

        std::cout << futu.get() << std::endl;

    }
}
