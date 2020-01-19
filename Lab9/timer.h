#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <iostream>

class Timer
{
public:
    Timer();
    void start();
    void stop();
    double getSecondsElapsed();
private:
  std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
  std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
};

#endif // TIMER_H
