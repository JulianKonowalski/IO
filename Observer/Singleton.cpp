#include "Singleton.hpp"

Singleton* Singleton::sInstance{ nullptr };
std::mutex Singleton::sMutex;

Singleton* Singleton::getInstance() {
	std::lock_guard<std::mutex> lock(sMutex);
	if (!sInstance) { sInstance = new Singleton(0); }
	return sInstance;
}

int Singleton::getValue(void) const {
	std::lock_guard<std::mutex> lock(sMutex);
	return mValue;
}

void Singleton::log(const std::string& message) {
	std::lock_guard<std::mutex> lock(sMutex);
	mLogs.push_back(message);
}

void Singleton::setValue(const int& value) {
	std::lock_guard<std::mutex> lock(sMutex);
	mValue = value;
}