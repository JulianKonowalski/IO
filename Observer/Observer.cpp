#include "Observer.hpp"

#include <ctime>

int Observer::sIDVar(0);

void Observer::run(void) {
	while (true) {
		this->wait(WAITING_TIME);
		if (this->checkForChanges()) { this->logChange(); }
	}
}

bool Observer::checkForChanges(void) { //returns true if changed
	int value = mDataPool->getValue();
	if (value != mLastValue) {
		mLastValue = value;
		return true;
	}
	return false;
}

std::string getTimestamp(void) {
	time_t timestamp;
	time(&timestamp);
	return ctime(&timestamp);
}

void Observer::logChange(void) {
	std::string message = "Observer " + std::to_string(mID) + " noticed a change at " + getTimestamp();
	std::cout << message;
	mDataPool->log(message);
}