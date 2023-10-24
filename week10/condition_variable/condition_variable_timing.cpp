/*
Example: Thread synchronization with condition variable. No busy-wait.
*/

#include <chrono>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <iostream>
using namespace std;

// Global variables
std::mutex g_mutex;
std::condition_variable g_cv;
bool g_ready = false;


// Producer
void workThread() {
  // Simulate work for 60 seconds 
  std::cout << "Starting work thread ... \n";
  std::this_thread::sleep_for(std::chrono::seconds(60));
  std::unique_lock<std::mutex> ul(g_mutex);
  g_ready = true;
  ul.unlock();
  g_cv.notify_one();
}

// Consumer
void waitThread() {
  std::cout << "Inside wait thread ... \n";
  std::unique_lock<std::mutex> ul(g_mutex);
  g_cv.wait(ul, [] { return g_ready; }); // Predicate
  std::cout << "Wait Thread Executed! \n";

  // Unique lock with automatically released
}

int main() {
  std::thread t1(workThread);
  std::thread t2(waitThread);
  t1.join();
  t2.join();
  return 0;
}