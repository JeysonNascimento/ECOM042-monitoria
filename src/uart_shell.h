/*******************************************************************
 * @file uart_shell.h
 *
 * @brief Transporte da mini-shell
 *******************************************************************/

#ifndef UART_SHELL_H_
#define UART_SHELL_H_

#include <stddef.h>

#include <zephyr/device.h>

/** Mesma assinatura de cmd_dispatch(): linha -> resposta no buffer. */
typedef int (*uart_shell_dispatch_t)(const char *line, char *out, size_t len);

/**
 * Configura a ISR de RX em @p uart e cria a thread da shell, que entrega
 * cada linha completa para @p dispatch.
 */
int uart_shell_start(const struct device *uart, uart_shell_dispatch_t dispatch);

#endif /* UART_SHELL_H_ */
