/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:17:48 by linux-babas       #+#    #+#             */
/*   Updated: 2025/11/12 02:45:19 by linux-babas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Reallocates memory: grows/shrinks buffer to new size.
 * @param ptr Pointer to previous allocation.
 * @param old_size Readable size of the previous allocation, in bytes.
 * @param new_size New size, in bytes. Zero frees ptr and returns NULL.
 * @return New allocation, or NULL. On failure, ptr remains owned by caller.
 * @note Include the terminating NUL in old_size when preserving a string.
 */
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (!ptr)
		return (new_ptr);
	if (old_size < new_size)
		ft_memcpy(new_ptr, ptr, old_size);
	else
		ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}
