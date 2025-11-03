#include <iostream>
#include <ctime>
#include "src/timer.hpp"

using namespace std;

void get_the_system_time() {
    time_t current;
    time(&current);
    cout << "System time: " << ctime(&current);
}

void wait_for_a_few_seconds() {
    time_t start;
    time(&start);
    time_t current = start;
    while (difftime(current, start) < 3) {
        time(&current);
    }
}

int main() {
    Timer timer;
    
    time_t system_start;
    time(&system_start);
    get_the_system_time();
    
    timer.start();
    wait_for_a_few_seconds();
    timer.stop();
    
    time_t system_end;
    time(&system_end);
    get_the_system_time();
    
    cout << "Timer elapsed: " << timer.elapsed() << " seconds" << endl;
    cout << "System elapsed: " << difftime(system_end, system_start) << " seconds" << endl;
    
    return 0;
}
