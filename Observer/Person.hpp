#pragma once

#include "Singleton.hpp"

#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <time.h>

#define MIN_WAIT_TIME 500
#define MAX_WAIT_TIME 2000
#define MAX_AGE 100

class Person {
public:
	Person();
	void run();

private:
	void wait(const int& time) { std::this_thread::sleep_for(std::chrono::milliseconds(time)); }
	void changeAge(void) { mAge = rand() % MAX_AGE; std::cout << "\nPerson changed age to " << mAge << '\n'; }
	void notifySingleton(void) { mDataPool->setValue(mAge); }

	Singleton* mDataPool;
	int mAge;
};