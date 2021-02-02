#include "mbed.h"
#include "rtos.h"
#include <string.h>

class PPMOut {
public:
	PPMOut();
protected:
	Thread worker;
	void work();
};

PPMOut::PPMOut() {
	worker.start(callback(this, &PPMOut::work));
}

void PPMOut::work() {
	while (true) {
		ThisThread::sleep_for(100);
	}
}

int main() {
	PPMOut pout();

	while (true) {
		// Why no units? Important, figure out what changed. (e.g. 100ms)
		ThisThread::sleep_for(100);
	}
}
