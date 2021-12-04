/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:49:09 by ensebast          #+#    #+#             */
/*   Updated: 2021/10/11 23:02:10 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *target, char *str_control)
{
	int	i;

	i = 0;
	if (target == 0)
		return (0);
	while ((target[i] && str_control[i]) && target[i] == str_control[i])
	{
		i += 1;
	}
	if (target[i] && target[i] != str_control[i])
		return (0);
	return (1);
}
