/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:22:26 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/06/15 12:32:42 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/include/libft.h"

static void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		kill(SIGUSR1, sig);
	if (sig == SIGUSR2)
		kill(SIGUSR2, sig);
	else
		error_msg("received unexpected signal");
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (0);
}
