#pragma once

class State;

class Context {

public:
	Context(void);

	State* getState(void) { return mCurrentState; }
	void setState(State* state) { mCurrentState = state; }

private:
	State* mCurrentState;
	State** mAvailableStates;
};