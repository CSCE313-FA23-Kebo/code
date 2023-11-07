/*
Example: Thread synchronization without condition variable. Busy-wait implementation
*/

#include <chrono>
#include <mutex>
#include <thread>
#include <iostream>
using namespace std;

std::mutex g_mutex;
bool g_ready = false;  // not a condition variable!

// Producer : generate the data
void workThread() {
  std::this_thread::sleep_for(std::chrono::seconds(60));
  std::unique_lock<std::mutex> ul(g_mutex);
  g_ready = true;
  // No need to unlock !
} // Once we are out the function scope - the lock is automatically released


// Consumer will busy wait loop - Polling !
void waitThread() {
  while(!g_ready){// Wait on the flag

  }
  // Consume the data - use the data
  std::cout << "Wait Thread Executed! \n";
}

int main() {
  std::thread t1(workThread);
  std::thread t2(waitThread);
  t1.join();
  t2.join();
  return 0;
}