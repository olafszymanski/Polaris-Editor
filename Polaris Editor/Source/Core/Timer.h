#pragma once

class Timer
{
public:
	static void Tick();

	// Getters
	inline static const float& GetDeltaTime() { return s_DeltaTime; }
	inline static const unsigned int& GetFramesPerSecond() { return s_FramesPerSecond; }

private:
	static float s_DeltaTime;
	static unsigned int s_FramesPerSecond;

private:
	Timer() = default;
	~Timer() = default;

	static void CalculateDeltaTime();
	static void CalculateFramesPerSecond();
};