#pragma once

#include <iostream>
#include "State.h"

class ConcreteState3 : public State { 
public:
	using State::State; //use the constructor of the parent class
	void sayHi(void) override { std::cout << "Hi! Im state 3 :D\n"; }
};