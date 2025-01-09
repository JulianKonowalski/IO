#include <thread>
#include <chrono>
#include <cstdlib>

#include "Warehouse.h"
#include "Director.h"

void supplier(void) {
	Warehouse* instance = Warehouse::getInstance();
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 500));
		instance->resetResources();
	}
}

void factory(void) {
	Director director;

	while (true) {
		if (rand() % 2) {
			Computer* pc = director.constructPC();
			std::cout << "Constructed a PC\n";
			delete pc;
		} else {
			Computer* notebook = director.constructNotebook();
			std::cout << "Constructed a Notebook!\n";
			delete notebook;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 500));
	}
}

int main(void) {
	srand((unsigned)time(nullptr));
	std::thread construct1(&factory);
	construct1.join();

	return 0;
}