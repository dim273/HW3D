//CPU��ʱ��
#pragma once

#ifndef CPU_TIMER_H
#define CPU_TIMER_H

class CpuTimer
{
public:
	CpuTimer();

	float TotalTimer() const;	//���ش�Reset()����֮�󾭹���ʱ�䣬��������ͣ�ڼ��
	float DeltaTimer() const;	//����ÿ֡�ļ��ʱ��

	void Reset();	//���ü�ʱ
	void Start();	//��ʼ��ʱ��ȡ����ͣʱ����
	void Stop();	//��Ҫ��ͣʱ����
	void Tick();	//ÿһ֡��ʼʱ����
	bool IsStopped() const;		//��ʱ���Ƿ���ͣ�����

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
