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

#include "client.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

int main(int argc, char **argv)
{
    int     serverPID;
    char    *str;

    serverPID = ft_atoi(argv[1]);
    str = argv[2];
    ft_printf("%d\n", argc);
    
    return (0);
}