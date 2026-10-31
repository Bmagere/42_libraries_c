/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_clear.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 00:00:00 by bamagere          #+#    #+#             */
/*   Updated: 2026/10/31 00:00:00 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @brief Provides access to the internal pending-line storage.
 * @return Static slot array shared by get_next_line and its cleanup function.
 * @note Internal helper; callers must not free the array itself.
 */
char	**gnl_storage(void)
{
	static char	*storage[GNL_MAX_FD];

	return (storage);
}

/**
 * @brief Frees pending text without closing any file descriptor.
 * @param fd Descriptor to clear, or -1 to clear all pending readers.
 * @note Other out-of-range values are ignored. Safe to call repeatedly.
 */
void	get_next_line_clear(int fd)
{
	char	**storage;
	int		i;

	storage = gnl_storage();
	if (fd >= 0 && fd < GNL_MAX_FD)
	{
		free(storage[fd]);
		storage[fd] = NULL;
	}
	if (fd != -1)
		return ;
	i = 0;
	while (i < GNL_MAX_FD)
	{
		free(storage[i]);
		storage[i++] = NULL;
	}
}
