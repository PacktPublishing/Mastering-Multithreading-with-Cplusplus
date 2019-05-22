#include <thread>
#include <string>

void worker(int n, std::string t) {
 // Business logic.
}

int main () {
   std::string s = "Test";
   int i = 1;
   std::thread t(worker, i, s);
   t.join();
   return 0;
}
