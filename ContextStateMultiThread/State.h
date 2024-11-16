#pragma once

#include <stdexcept>
#include "Context.h"

class State {
public:
	State(Context* context) : mContext(context), mNextState(nullptr) {}
	State(Context* context, State* nextState) : mContext(context), mNextState(nextState) {}

	virtual void sayHi(void) = 0;

	void setNext(State* nextState) { mNextState = nextState; }
	void changeState(void) { 
		if (mNextState == nullptr) { throw new std::runtime_error("Unspecified next state"); } 
		mContext->setState(mNextState);
	}

protected:
	Context* mContext;
	State* mNextState;
};
