//CPU记时器
#pragma once

#ifndef CPU_TIMER_H
#define CPU_TIMER_H

class CpuTimer
{
public:
	CpuTimer();

	float TotalTimer() const;	//返回从Reset()调用之后经过的时间，不包括暂停期间的
	float DeltaTimer() const;	//返回每帧的间隔时间

	void Reset();	//重置记时
	void Start();	//开始计时或取消暂停时调用
	void Stop();	//需要暂停时调用
	void Tick();	//每一帧开始时调用
	bool IsStopped() const;		//计时器是否暂停或结束

private:
	double m_SecondsPerCount = 0.0;
	double m_DeltaTime = -1.0;

	__int64 m_BaseTime = 0;
	__int64 m_PausedTime = 0;
	__int64 m_StopTime = 0;
	__int64 m_PrevTime = 0;
	__int64 m_CurrTime = 0;

	bool m_Stopped = false;
};

#endif
