/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:22:26 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/06/16 16:43:37 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/include/libft.h"

void	send_sig(int pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_printf("No connection with server");
		exit(EXIT_FAILURE);
	}
	usleep(100);
}

void	send_bits(const int pid, char c, int octet)
{
	while (octet >= 0)
	{
		if (((c >> octet) & 1) == 1)
			send_sig(pid, SIGUSR1);
		else
			send_sig(pid, SIGUSR2);
		octet--;
		usleep(1100);
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc <= 2 || argc >= 4)
	{
		if (argc <= 2)
			ft_printf("Too few arguments");
		if (argc >= 4)
			ft_printf("Too many arguments");
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	i = -1;
	while (argv[2][++i])
		send_bits(pid, argv[2][i], 7);
	return (0);
}
