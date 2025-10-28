#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>

class Timer {
private:
    time_t start_time;
    time_t end_time;
    bool is_running;
    bool has_been_started;

public:
    Timer();
    void start();
    void stop();
    long elapsed() const;
};

#endif
