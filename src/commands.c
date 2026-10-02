#include "commands.h"

#include <errno.h>

#include <zephyr/kernel.h>

int led_on_execute(void *ctx)
{
	struct led *led = ctx;

	if (led == NULL) {
		return -EINVAL;
	}

	led->on = true;
	printk("%s: ON\n", led->label);

	return 0;
}

int led_off_execute(void *ctx)
{
	struct led *led = ctx;

	if (led == NULL) {
		return -EINVAL;
	}

	led->on = false;
	printk("%s: OFF\n", led->label);

	return 0;
}

int led_toggle_execute(void *ctx)
{
	struct led *led = ctx;

	if (led == NULL) {
		return -EINVAL;
	}

	led->on = !led->on;
	printk("%s: TOGGLE -> %s\n", led->label, led->on ? "ON" : "OFF");

	return 0;
}

int led_status_execute(void *ctx)
{
	const struct led *led = ctx;

	if (led == NULL) {
		return -EINVAL;
	}

	printk("%s: status = %s\n", led->label, led->on ? "ON" : "OFF");

	return 0;
}
