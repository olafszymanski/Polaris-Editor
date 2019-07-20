#pragma once

class StringHelper
{
public:
	static std::string GetFileExtension(const std::string& filePath);
	static std::string GetDirectoryFromPath(const std::string& filePath);

private:
	StringHelper() = default;
	~StringHelper() = default;
};