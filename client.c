/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:22:26 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/06/12 19:36:19 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/include/libft.h"

static void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("%d", sig);
	if (sig == SIGUSR2)
		ft_printf("%d", sig);
	else
		error_msg("received unexpected signal");
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (0);
}
