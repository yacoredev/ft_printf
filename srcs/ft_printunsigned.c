/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <yabaadi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:02:24 by yabaadi           #+#    #+#             */
/*   Updated: 2026/11/06 16:30:34 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static ssize_t	ft_rec_putnbr(unsigned int nbr)
{
	char	c;
	ssize_t	count;

	if (nbr == 0)
		return (0);
	count = ft_rec_putnbr(nbr / 10);
	if (count < 0)
		return (-1);
	c = (nbr % 10) + '0';
	if (write(1, &c, 1) < 0)
		return (-1);
	return (count + 1);
}

ssize_t	ft_printunsigned(unsigned int n)
{
	ssize_t	count;

	if (n == 0)
		return (write(1, "0", 1));
	count = ft_rec_putnbr(n);
	if (count < 0)
		return (-1);
	return (count);
}
