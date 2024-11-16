#include "Client.h"

#include <iostream>
#include <mutex>

#include "State.h"

void Client::run(void) {
	std::cout << "Press ENTER to change the context state.\n";
	std::cout << "Press q to exit.\n\n";

	std::mutex* contextMutex = mContext->getMutex();
	std::condition_variable* contextCv = mContext->getConditionVariable();

	while (true) {
		if (waitForInput()) { break; }
		contextMutex->lock();
		mContext->getState()->changeState();
		contextMutex->unlock();
		contextCv->notify_all();
	}
}

bool Client::waitForInput(void) {
	char input = getchar();
	return input == 'q';
}