#pragma once

#include "Context.h"

class Client {
public:
	Client(Context* context) : mContext(context) {}

	void run(void);

private:
	bool waitForInput(void);

	Context* mContext;
};