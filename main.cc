#include "mbed.h"
#include "rtos.h"
#include <string.h>

#include <chrono>
using namespace std::chrono;

DigitalOut led(LED1);
DigitalOut ppm(D2);

class PPMOut {
public:
	PPMOut(DigitalOut pin);
protected:
	Timeout timeout;
	DigitalOut _pin;
	bool state;

	void timer_expired();
};

PPMOut::PPMOut(DigitalOut pin) : _pin(pin) {
	state = 0;
	timeout.attach_us(callback(this, &PPMOut::timer_expired), 1);
}

void PPMOut::timer_expired() {
	if (!state) {
		// Off to on.
		state = 1; _pin = 1;
		timeout.attach_us(callback(this, &PPMOut::timer_expired), 1400);
		led = !led;
	} else if (state) {
		// On to off.
		state = 0; _pin = 0;
		timeout.attach_us(callback(this, &PPMOut::timer_expired), 2000 - 1400);
		led = !led;
	}
}

int main() {
	led = 0;
	printf("=== boot.\r\n");
	PPMOut pout(ppm);

	while (true) {
		// Why no units? Important, figure out what changed. (e.g. 100ms)
		ThisThread::sleep_for(1000);
		printf(".\r\n");
	}
}
