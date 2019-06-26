#include "pch.h"

#include "Timer.h"

float Timer::s_DeltaTime = 0.0f;

unsigned int Timer::s_FramesPerSecond = 0;

void Timer::Tick()
{
	CalculateDeltaTime();
	CalculateFramesPerSecond();
}

void Timer::CalculateDeltaTime()
{
	static __int64 currentTime = 0;
	static __int64 countsPerSecond = 0;
	static __int64 previousTime = 0;

	QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&countsPerSecond));

	previousTime = currentTime;

	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentTime));

	s_DeltaTime = (currentTime - previousTime) * (1.0f / countsPerSecond);
}
void Timer::CalculateFramesPerSecond()
{
	static unsigned int framesCount = 0;
	static float elapsedTime = 0.0f;

	++framesCount;

	elapsedTime += s_DeltaTime;

	if (elapsedTime >= 1.0f)
	{
		s_FramesPerSecond = framesCount;

		framesCount = 0;
		elapsedTime = 0.0f;
	}
}