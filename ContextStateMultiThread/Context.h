#pragma once

#include <mutex>

class State;

class Context {

public:
	Context(void);

	State* getState(void) { return mCurrentState; }
	void setState(State* state) { mCurrentState = state; }

	std::mutex* getMutex(void) { return &mMutex; }
	std::condition_variable* getConditionVariable(void) { return &mConditionVariable; }

	void run(void);

private:
	std::mutex mMutex;
	std::condition_variable mConditionVariable;
	State* mCurrentState;
	State** mAvailableStates;
};