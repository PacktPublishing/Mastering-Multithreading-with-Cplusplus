#include <thread>
#include <string>
#include <utility>

void worker(int n, string t) {
   // Business logic.
}

int main () {
   std::string s = "Test";
   std::thread t0(worker, 1, s);
   std::thread t1(std::move(t0));
   t1.join();
   return 0;
}
