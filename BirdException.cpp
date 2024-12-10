#include"BirdExpection.h"
#include<sstream>

BirdException::BirdException(int line, const char* file) noexcept
	: line(line), file(file)
{}

const char* BirdException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl << GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* BirdException::GetType() const noexcept
{
	return "Bird Exception";
}

int BirdException::GetLine() const noexcept
{
	return line;
}

std::string BirdException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File]" << file << std::endl << "[Line]" << line;
	return oss.str();
}