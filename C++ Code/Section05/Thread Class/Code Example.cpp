#include <thread>

void worker() {
 // Business logic.
}

int main () {
 std::thread t(worker);
 return 0;
 }
