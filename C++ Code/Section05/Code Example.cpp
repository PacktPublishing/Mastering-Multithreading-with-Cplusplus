#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;
mutex m;
condition_variable cv;
bool ready = false;
ThreadLocal result;

void worker() {
   unique_lock<mutex> ulock(m);
   result = thread_local_method();
         ready = true;
         std::notify_all_at_thread_exit(cv, std::move(ulock));
}

int main() {
         thread t(worker);
         t.detach();
         // Do work here.
         unique_lock<std::mutex> ulock(m);
         while(!ready) {
               cv.wait(ulock);
         }
         // Process result
}
