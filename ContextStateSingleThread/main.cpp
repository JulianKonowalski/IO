#include "Context.h"
#include "Client.h"
#include <thread>

int main(void) {
	Context* context = new Context();
	Client* client = new Client(context);

	std::thread userThread(&Client::run, client);
	std::thread contextThread(&Context::run, context);
	userThread.join();
	contextThread.join();

	return 0;
}