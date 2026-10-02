#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <stdbool.h>

struct led {
	const char *label;
	bool on;
};

int led_on_execute(void *ctx);
int led_off_execute(void *ctx);
int led_toggle_execute(void *ctx);
int led_status_execute(void *ctx);

#endif
