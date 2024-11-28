#include "Person.hpp"

Person::Person() {
	srand((unsigned)time(nullptr));
	changeAge();
	mDataPool = Singleton::getInstance();
	mDataPool->setValue(mAge);
}

void Person::run() {
	while (true) {
		this->wait(MIN_WAIT_TIME + (rand() % MAX_WAIT_TIME - MIN_WAIT_TIME));
		this->changeAge();
		this->notifySingleton();
	}
}