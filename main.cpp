#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

#include "src/timer.hpp"

using namespace std;

time_t start_system_time;
time_t end_system_time;

void get_the_system_time() {
    time_t current_time;
    time(&current_time);
    cout << "Current system time: " << ctime(&current_time);
}

void wait_for_a_few_seconds() {
    cout << "Waiting for 3 seconds..." << endl;
    this_thread::sleep_for(chrono::seconds(3));
}

void compare_the_times() {
    time(&end_system_time);
    long system_elapsed = difftime(end_system_time, start_system_time);
    cout << "System time elapsed: " << system_elapsed << " seconds" << endl;
}

int main() {
  Timer timer;
  time(&start_system_time);
  get_the_system_time();
  timer.start();
  wait_for_a_few_seconds();
  timer.stop();
  get_the_system_time();
  cout << "Timer elapsed: " << timer.elapsed() << " seconds" << endl;
  compare_the_times();
  return 0;
}
