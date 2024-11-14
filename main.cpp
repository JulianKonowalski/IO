#include "Context.h"
#include "State.h"

int main(void) {
	Context* context = new Context();
	for (int i = 0; i < 3; ++i) {
		State* currentState = context->getState();
		currentState->sayHi();
		currentState->changeState();
	}
	return 0;
}