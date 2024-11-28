#pragma once

#pragma warning(disable : 4996)

#include <iostream>

#include "Singleton.hpp"

#define WAITING_TIME 100

class Observer {
public:
	Observer(Singleton* dataPool) : mDataPool(dataPool), mLastValue(dataPool->getValue()), mID(++sIDVar) {}
	void run(void);

private:
	void wait(const int& time) { std::this_thread::sleep_for(std::chrono::milliseconds(time)); }
	bool checkForChanges(void);
	void logChange(void);

	int mID;
	int mLastValue;
	Singleton* mDataPool;

	static int sIDVar; //for giving out IDs
};