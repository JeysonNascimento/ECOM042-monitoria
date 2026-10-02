/*******************************************************************
 * @file main.c
 *
 * @brief Main file.
 * @author João Matheus Nascimento Dias (jmnd@ic.ufal.br)
 * @version 0.1
 * @date 26/08/2026
 *******************************************************************/

#include "command.h"
#include "commands.h"

#include <errno.h>

#include <zephyr/kernel.h>

static struct led led0 = {.label = "led0", .on = false};

static const struct command cmd_led_on = {
	.name = "led_on",
	.execute = led_on_execute,
	.ctx = &led0,
};

static const struct command cmd_led_off = {
	.name = "led_off",
	.execute = led_off_execute,
	.ctx = &led0,
};

static const struct command cmd_led_toggle = {
	.name = "led_toggle",
	.execute = led_toggle_execute,
	.ctx = &led0,
};

static const struct command cmd_led_status = {
	.name = "led_status",
	.execute = led_status_execute,
	.ctx = &led0,
};

static const struct command *const command_table[] = {
	&cmd_led_on,
	&cmd_led_off,
	&cmd_led_toggle,
	&cmd_led_status,
};

static const char *const requests[] = {
	"led_on", "led_status", "led_toggle", "led_status", "led_toggle", "led_off", "reboot",
};

int main(void)
{
	printk("Command Pattern demo on %s\n", CONFIG_BOARD_TARGET);

	for (size_t i = 0; i < ARRAY_SIZE(requests); i++) {
		int ret = command_dispatch(command_table, ARRAY_SIZE(command_table), requests[i]);

		if (ret == -ENOENT) {
			printk("unknown command: %s\n", requests[i]);
		} else if (ret < 0) {
			printk("command %s failed: %d\n", requests[i], ret);
		}
	}

	return 0;
}
