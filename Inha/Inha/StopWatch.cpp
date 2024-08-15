#include "StopWatch.h"

StopWatch::StopWatch()
{
    startTime = clock();
    endTime = clock();
}

void StopWatch::start()
{
    startTime = clock();
}

void StopWatch::stop()
{
    endTime = clock();
}

clock_t StopWatch::getStartTime()
{
    return startTime;
}

clock_t StopWatch::getEndTime()
{
    return endTime;
}

clock_t StopWatch::getElpasedTime()
{
    return endTime - startTime;
}
