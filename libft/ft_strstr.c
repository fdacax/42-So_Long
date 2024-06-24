/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:03:17 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/06/24 18:03:17 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;

	j = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	i = 0;
	while (str[i])
	{
		while (to_find[j] && str[i + j]
			&& to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
