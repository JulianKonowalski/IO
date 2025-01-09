#pragma once

#include "Warehouse.h"
#include "Computer.h"

class Builder {
public:
	Builder() : mWarehouse(Warehouse::getInstance()), mComputer(nullptr) {}

	void reset() { mComputer = new Computer(); }

	void setCpu(const int& count) {
		if (!mWarehouse->getResource(CPU, count)) {
			throw std::runtime_error("Not enough CPUs in the warehouse");
			exit(0);
		};
		mComputer->setCpuCount(count); 
	}

	void setRam(const int& count) { 
		if (!mWarehouse->getResource(RAM, count)) {
			throw std::runtime_error("Not enough RAM in the warehouse\n");
			exit(0);
		};
		mComputer->setRamCount(count); 
	}
	
	void setDrive(const int& count) {
		if (!mWarehouse->getResource(Drive, count)) {
			throw std::runtime_error("Not enough drives in the warehouse\n");
			exit(0);
		};
		mComputer->setDriveCount(count); 
	}

	Computer* getProduct(void) { return mComputer; }

private:
	Warehouse* mWarehouse;
	Computer* mComputer;
};
