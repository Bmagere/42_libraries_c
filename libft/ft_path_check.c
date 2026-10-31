/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 10:01:59 by bamagere          #+#    #+#             */
/*   Updated: 2026/10/31 10:02:00 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks whether a path can be opened and closed for reading.
 * @param str Path string to check.
 * @return 1 on success, 0 for NULL, open failure or close failure.
 * @note Never exits the program or closes a descriptor owned by the caller.
 */
int	ft_path_check(char *str)
{
	int	fd_path;

	if (!str)
		return (0);
	fd_path = open(str, O_RDONLY);
	if (fd_path < 0)
		return (0);
	return (close(fd_path) == 0);
}
