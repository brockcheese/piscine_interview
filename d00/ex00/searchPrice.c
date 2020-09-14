/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:47:37 by bpace             #+#    #+#             */
/*   Updated: 2020/02/24 12:55:02 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	searchPrice(struct s_art **arts, char *name) {
	int i;

	i = -1;
	while(arts[++i]) {
		if (strcmp(arts[i]->name, name) == 0)
			return (arts[i]->price);
	}
	return (-1);
}
