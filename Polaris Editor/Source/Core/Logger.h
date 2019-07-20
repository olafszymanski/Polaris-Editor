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
	#define POLARIS_ASSERT(x, message)								\
		if (!x)																\
		{																	\
			Logger::Error(message, __FILENAME__, __LINE__);					\
			__debugbreak();													\
		}
	#define POLARIS_DX_ASSERT(x, message)									\
		if (FAILED(x))														\
		{																	\
			Logger::Error(message, __FILENAME__, __LINE__);					\
			__debugbreak();													\
		}
#else
	#define POLARIS_ASSERT(x, message) x;
	#define POLARIS_DX_ASSERT(x, message) x;
#endif