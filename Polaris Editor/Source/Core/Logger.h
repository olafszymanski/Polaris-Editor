#pragma once

class Logger
{
public:
	static void Error(const std::string& message, const std::string& filename, unsigned int line);

private:
	Logger() = default;
	~Logger() = default;
};

#ifdef _DEBUG
	#define POLARIS_ASSERT(x, message) \
		if (typeid(x).name() == "long" && FAILED(x)) Logger::Error(message, __FILENAME__, __LINE__); \
		else if (!x) Logger::Error(message, __FILENAME__, __LINE__);
#else
	#define POLARIS_ASSERT(x, message) x;
#endif