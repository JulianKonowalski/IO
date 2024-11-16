#pragma once

#include <iostream>
#include "State.h"

class ConcreteState2 : public State { 
public:
	using State::State; //use the constructor of the parent class
	void sayHi(void) override { std::cout << "Hi! Im state 2 :D\n"; }
};