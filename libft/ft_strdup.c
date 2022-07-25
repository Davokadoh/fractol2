/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleroux <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:01:03 by jleroux           #+#    #+#             */
/*   Updated: 2021/10/22 17:48:17 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc((ft_strlen(src) + 1) * sizeof(*src));
	if (!str)
		return (NULL);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*mystr;

	mystr = "test";
	printf("%s\n", mystr);
	printf("%s\n", ft_strdup(mystr));
}
*/
