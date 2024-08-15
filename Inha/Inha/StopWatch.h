#pragma once
#include <chrono>

class StopWatch
{
private:
	clock_t startTime;
	clock_t endTime;

public:
	StopWatch();
	~StopWatch() { };

	void start();
	void stop();

	clock_t getStartTime();
	clock_t getEndTime();
	clock_t getElpasedTime();
};

