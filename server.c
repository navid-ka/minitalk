/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:22:31 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/06/16 16:20:51 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/include/libft.h"

void	handler(int sig)
{
	static int				bits = 0;
	static unsigned char	c = '\0';

	c <<= 1;
	if (sig == SIGUSR1)
		c |= 1;
	bits++;
	if (bits == 8)
	{
		if ((int)c <= 126)
			ft_printf("%c", c);
		else if ((int)c >= 127)
			ft_printf("%c", c);
		bits = 0;
		c = '\0';
	}
}

int	main(void)
{
	int	pid;
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	pid = getpid();
	if (!pid)
		ft_printf("PID NOT AVAILABLE RESTART THE SERVER");
	else
		ft_printf("Server PID: %i\n", getpid());
	while (1)
		sleep(1);
	return (0);
}
