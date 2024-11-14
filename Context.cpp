#include "Context.h"

#include "State.h"
#include "ConcreteState1.h"
#include "ConcreteState2.h"
#include "ConcreteState3.h"

#include <iostream> //TO USUNAC, TYLKO NA POTRZEBY DEMONSTRACJI

Context::Context(void) {
	mAvailableStates = new State*[3];
	mAvailableStates[2] = new ConcreteState3(this);
	mAvailableStates[1] = new ConcreteState2(this, mAvailableStates[2]);
	mAvailableStates[0] = new ConcreteState1(this, mAvailableStates[1]);
	mAvailableStates[2]->setNext(mAvailableStates[0]);

	mCurrentState = mAvailableStates[0];

	std::cout << "Context created successfully :)\n";
}