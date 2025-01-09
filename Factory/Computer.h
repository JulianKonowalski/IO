#pragma once

class Computer {
public:
	Computer(int cpuCount = 0, int ramCount = 0, int driveCount = 0) : mCpuCount(cpuCount), mRamCount(ramCount), mDriveCount(driveCount) {}

	void setCpuCount(const int& count) { mCpuCount = count; }
	void setRamCount(const int& count) { mRamCount = count; }
	void setDriveCount(const int& count) { mDriveCount = count; }

protected:
	int mCpuCount;
	int mRamCount;
	int mDriveCount;
};