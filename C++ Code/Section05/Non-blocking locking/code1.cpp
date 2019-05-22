#include <chrono>
#include <mutex>
#include <thread>
#include <iostream>

std::chrono::milliseconds interval(50);

std::mutex mutex;
int shared_counter = 0;
int exclusive_counter = 0;

void worker0() {
   std::this_thread::sleep_for(interval);
         while (true) {
            if (mutex.try_lock()) {
                std::cout << "Shared (" << shared_counter << ")\n";
                mutex.unlock();
                return;
               }
         else {
                ++exclusive_counter;
                std::cout << "Exclusive (" << exclusive_counter << ")\n";
                std::this_thread::sleep_for(interval);
               }
         }
}
void worker1() {
   mutex.lock();
         std::this_thread::sleep_for(10 * interval);
         ++shared_counter;
         mutex.unlock();
}
int main() {
         std::thread t1(worker0);
         std::thread t2(worker1);
         t1.join();
         t2.join();
}
