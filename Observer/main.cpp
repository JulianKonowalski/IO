#include <thread>

#include "Person.hpp"
#include "Singleton.hpp"
#include "Observer.hpp"

int main(void) {

	Person person;
	Observer observer1(Singleton::getInstance());
	Observer observer2(Singleton::getInstance());
	Observer observer3(Singleton::getInstance());

	std::thread personThread(&Person::run, &person);

	std::thread observerThread1(&Observer::run, &observer1);
	std::thread observerThread2(&Observer::run, &observer2);
	std::thread observerThread3(&Observer::run, &observer3);


	personThread.join();
	observerThread1.join();
	observerThread2.join();
	observerThread3.join();

	return 0;
}