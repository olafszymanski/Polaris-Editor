#include "pch.h"

#include "Logger.h"

void Logger::Error(const std::string& message, const std::string& filename, unsigned int line)
{
	std::stringstream messageBoxMessage;
	messageBoxMessage << "'" << message << "' in '" << filename << "' at line " << line << ".";

	MessageBox(NULL, messageBoxMessage.str().c_str(), "Polaris Editor Error", MB_OK | MB_ICONERROR);
}
void Logger::Warning(const std::string& message, const std::string& filename, unsigned int line)
{
	MessageBox(NULL, message.c_str(), "Polaris Editor Warning", MB_OK | MB_ICONWARNING);
}