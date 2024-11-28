#pragma once

#include <mutex>
#include <vector>

class Singleton {

	friend class Person;

public:
	Singleton(const Singleton& other) = delete;
	void operator=(const Singleton& other) = delete;

	static Singleton* getInstance();
	int getValue(void) const;
	void log(const std::string& message);

protected:
	Singleton(const int& value) : mValue(value) {}
	~Singleton() { delete sInstance; }
	void setValue(const int& value);

private:
	int mValue;
	std::vector<std::string> mLogs;
	static std::mutex sMutex;
	static Singleton* sInstance;
};