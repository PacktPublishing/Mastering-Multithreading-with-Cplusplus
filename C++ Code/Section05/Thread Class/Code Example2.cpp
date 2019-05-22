#include <thread>

void worker() {
 // Business logic.
}

int main () {
 std::thread t(worker);
 t.join();
 return 0;
}
