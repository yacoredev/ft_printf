/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <yabaadi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:02:10 by yabaadi           #+#    #+#             */
/*   Updated: 2026/11/10 06:42:19 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static ssize_t	ft_rec_putnbr(long nbr)
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

static ssize_t	check_sign(long *nbr)
{
	ssize_t	count;

	count = 0;
	if (*nbr < 0)
	{
		count = write(1, "-", 1);
		if (count < 0)
			return (-1);
		*nbr = -*nbr;
	}
	return (count);
}

ssize_t	ft_printnumber(int n)
{
	long	nbr;
	ssize_t	count;
	ssize_t	re;

	nbr = (long)n;
	count = check_sign(&nbr);
	if (count < 0)
		return (-1);
	if (nbr == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		return (count + 1);
	}
	re = ft_rec_putnbr(nbr);
	if (re < 0)
		return (-1);
	return (count + re);
}
