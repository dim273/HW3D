#include"BirddimTimer.h"

using namespace std::chrono;

BirddimTimer::BirddimTimer()
{
	last = steady_clock::now();
}

float BirddimTimer::Mark()
{
	//返回一个时间差
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTimer = last - old;
	return frameTimer.count();
}

float BirddimTimer::Peek() const
{
	return duration<float>(steady_clock::now() - last).count();
}