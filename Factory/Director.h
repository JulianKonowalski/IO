#pragma once

#include "Computer.h"
#include "Builder.h"

class Director {
public:

	Computer* constructPC(void) {
		Builder builder;
		
		builder.reset();
		builder.setCpu(1);
		builder.setRam(2);
		builder.setDrive(1);

		return builder.getProduct();
	}

	Computer* constructNotebook(void) {
		Builder builder;

		builder.reset();
		builder.setCpu(1);
		builder.setRam(1);
		builder.setDrive(2);

		return builder.getProduct();
	}
};