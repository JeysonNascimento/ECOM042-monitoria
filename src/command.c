#include "command.h"

#include <errno.h>
#include <string.h>

int command_execute(const struct command *cmd)
{
	if (cmd == NULL || cmd->execute == NULL) {
		return -EINVAL;
	}

	return cmd->execute(cmd->ctx);
}

const struct command *command_find(const struct command *const table[], size_t count,
				   const char *name)
{
	if (table == NULL || name == NULL) {
		return NULL;
	}

	for (size_t i = 0; i < count; i++) {
		if (table[i] != NULL && table[i]->name != NULL &&
		    strcmp(table[i]->name, name) == 0) {
			return table[i];
		}
	}

	return NULL;
}

int command_dispatch(const struct command *const table[], size_t count, const char *name)
{
	if (table == NULL || name == NULL) {
		return -EINVAL;
	}

	const struct command *cmd = command_find(table, count, name);

	if (cmd == NULL) {
		return -ENOENT;
	}

	return command_execute(cmd);
}
