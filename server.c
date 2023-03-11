/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:33:54 by abertoli          #+#    #+#             */
/*   Updated: 2022/10/21 18:29:38 by abertoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static void	sig_handler(int signo)
{
	static int	n = 0;
	static int	number_signals = 0;

	if (signo == SIGUSR2)
		n = n | (128 >> number_signals);
	number_signals++;
	if (number_signals == 8)
	{
		ft_printf("%c", n);
		number_signals = 0;
		n = 0;
	}
}

int	main(void)
{
	pid_t				process_id;
	struct sigaction	sigact;

	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = 0;
	sigact.sa_flags = sigact.sa_flags | SA_NODEFER;
	sigact.sa_handler = sig_handler;
	process_id = getpid();
	ft_printf("%d\n", process_id);
	while (42)
	{
		sigaction(SIGUSR1, &sigact, NULL);
		sigaction(SIGUSR2, &sigact, NULL);
	}
	return (0);
}
