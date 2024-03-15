/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:14:55 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/11/07 12:22:36 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_mod(const char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 && s2)
	{
		str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		i = 0;
		j = 0;
		while (s1[i])
			str[j++] = s1[i++];
		i = 0;
		while (s2[i])
			str[j++] = s2[i++];
		str[j] = '\0';
		return (str);
	}
	free((void *)s1);
	if (!s1)
		return (ft_strdup(s2));
	return (NULL);
}
