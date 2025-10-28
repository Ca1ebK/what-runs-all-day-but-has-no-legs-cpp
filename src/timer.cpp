#include "timer.hpp"

Timer::Timer() : is_running(false), has_been_started(false) {
}

void Timer::start() {
    if (!is_running) {
        time(&start_time);
        is_running = true;
        has_been_started = true;
    }
}

void Timer::stop() {
    if (is_running) {
        time(&end_time);
        is_running = false;
    }
}

long Timer::elapsed() const {
    if (!has_been_started) {
        return 0;
    }
    
    time_t current_end = end_time;
    if (is_running) {
        time(&current_end);
    }
    
    return difftime(current_end, start_time);
}
