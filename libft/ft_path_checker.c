/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 10:02:07 by bamagere          #+#    #+#             */
/*   Updated: 2026/10/31 10:02:09 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Checks a readable path and exits with failure if it is invalid.
 * @param str Path string to check.
 * @note Prints an error and calls exit(EXIT_FAILURE) if the check fails.
 */
void	ft_path_checker(char *str)
{
	if (!ft_path_check(str))
	{
		ft_puts("Error\nA path format has gone wrong or doesn't exist.");
		exit(EXIT_FAILURE);
	}
}
