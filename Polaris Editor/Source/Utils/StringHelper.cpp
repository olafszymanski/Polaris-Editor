#include "pch.h"

#include "StringHelper.h"

std::string StringHelper::GetFileName(const std::string& filePath)
{
	size_t position = filePath.find_last_of("\\/");

	return std::string::npos != position ? filePath.substr(position + 1) : "";
}
std::string StringHelper::GetFileExtension(const std::string& filePath)
{
	size_t position = filePath.find_last_of(".");

	return std::string::npos != position ? filePath.substr(position, filePath.length()) : "";
}
std::string StringHelper::GetDirectoryFromPath(const std::string& filePath)
{
	size_t position = filePath.find_last_of("\\/");

	return std::string::npos != position ? filePath.substr(0, position + 1) : "";
}