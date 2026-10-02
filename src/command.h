#ifndef COMMAND_H_
#define COMMAND_H_

#include <stddef.h>

typedef struct command {
	const char *name;
	int (*execute)(void *ctx);
	void *ctx;
} command_t;

int command_execute(const struct command *cmd);

const struct command *command_find(const struct command *const table[], size_t count,
				   const char *name);

int command_dispatch(const struct command *const table[], size_t count, const char *name);

#endif
