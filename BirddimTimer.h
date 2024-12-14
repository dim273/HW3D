#pragma once
#include<chrono>

class BirddimTimer
{
public:
	BirddimTimer();
	float Mark();
	float Peek() const;
private:
	std::chrono::steady_clock::time_point last;
};