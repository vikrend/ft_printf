/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 10:21:37 by astrielov         #+#    #+#             */
/*   Updated: 2018/03/28 10:28:44 by astrielov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../libft/libft.h"

void	parse_precision(char **format, va_list va, t_pf *arg)
{
	if (**format == '.')
	{
		arg->flags |= FLAG_GOT_PRECISION;
		(*format)++;
		if (ft_isdigit(**format))
			arg->precision = parse_atoi(format);
		else if (**format == '*')
		{
			arg->precision = (unsigned int)va_arg(va, int);
			(*format)++;
		}
	}
}
