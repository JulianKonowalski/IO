#pragma once 

#include <mutex>
#include <iostream>

enum ComputerResource {
	CPU, 
	RAM,
	Drive
};

class Warehouse {
public:

	Warehouse(Warehouse& other) = delete;
	void operator=(const Warehouse& other) = delete;

	static Warehouse* getInstance(void);

	void resetResources(void);
	bool getResource(const ComputerResource& resource, const int& count);

private:

	Warehouse() : mMaxAmount(10) { mCpuCount = mRamCount = mDriveCount = mMaxAmount; }
	
	static Warehouse* mInstance;

	std::mutex mMutex;

	int mCpuCount;
	int mRamCount;
	int mDriveCount;
	const int mMaxAmount;
};
