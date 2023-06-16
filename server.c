/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:22:31 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/06/15 12:34:57 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/include/libft.h"

static char	*error_msg(char *s)
{
	ft_printf("%s", s);
	exit(-1);
}

static unsigned char	*print_bits(int *bits)
{
	int	i;

	i = 8
	while (i--)
	{
		if (SIGUSR1 == 1)
	}
}

int	main(void)
{
	if (signal(SIGUSR1, signal_handler) == -1)
		error_msg("can't catch SIGUSR1");
	if (signal(SIGUSR2, signal_handler) == -1)
		error_msg("can't catch SIGUSR2");
	ft_printf("PID of server: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}
