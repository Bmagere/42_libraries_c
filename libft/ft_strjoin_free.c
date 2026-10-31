/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:18:43 by linux-babas       #+#    #+#             */
/*   Updated: 2025/11/12 02:44:04 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Joins optional strings and consumes the flagged allocations.
 * @param s1 First string, or NULL.
 * @param s2 Second string, or NULL.
 * @param free_s1 If 1, frees s1 even on allocation failure.
 * @param free_s2 If 1, frees s2 even on allocation failure.
 * @return New owned string, or NULL on failure or if both inputs are NULL.
 * @note Identical inputs are freed only once; flagged inputs must be owned.
 */
char	*ft_strjoin_free(char *s1, char *s2, int free_s1, int free_s2)
{
	char	*new_s;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		new_s = ft_strdup(s2);
	else if (!s2)
		new_s = ft_strdup(s1);
	else
		new_s = ft_strjoin(s1, s2);
	if (s1 == s2 && free_s1 == 1)
		free_s2 = 0;
	if (free_s1 == 1)
		free(s1);
	if (free_s2 == 1)
		free(s2);
	return (new_s);
}
