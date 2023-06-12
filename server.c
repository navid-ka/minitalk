/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:22:31 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/06/12 17:19:09 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/include/libft.h"

static char	*error_msg(char *s)
{
	ft_printf("%s", s);
	exit(-1);
}

static void	signal_handler(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("%p", sig);
	else
		error_msg("received unexpected signal");
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (signal(SIGUSR2, signal_handler) == SIG_ERR)
		error_msg("can't catch SIGUSR2");
	while (1)
	{
		ft_printf("PID of server: \n%d", getpid());
		sleep(10);
	}
	return (0);
}
