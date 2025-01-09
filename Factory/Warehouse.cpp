#include "Warehouse.h"

Warehouse* Warehouse::mInstance = nullptr;

Warehouse* Warehouse::getInstance(void) {
	if (!mInstance) { mInstance = new Warehouse(); }
	return mInstance;
}

bool Warehouse::getResource(const ComputerResource& resource, const int& count) {
	std::lock_guard<std::mutex> lock(mMutex);
	switch (resource) {
	case CPU:
		if (mCpuCount < count) { return false; }
		mCpuCount -= count;
		break;
	case RAM:
		if (mRamCount  < count) { return false; }
		mRamCount -= count;
		break;
	case Drive:
		if (mDriveCount < count) { return false; }
		mDriveCount -= count;
		break;
	}
	return true;
}

void Warehouse::resetResources(void) {
	std::lock_guard<std::mutex> lock(mMutex);
	mCpuCount = mRamCount = mDriveCount = mMaxAmount;
}