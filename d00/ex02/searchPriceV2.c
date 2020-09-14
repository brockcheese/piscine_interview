/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 19:37:25 by bpace             #+#    #+#             */
/*   Updated: 2020/02/21 21:34:47 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int searchPriceHelper(struct s_art **arts, int start, int end, int check, char *name) {
	int cmp;

	cmp = strcmp(name, arts[check]->name);
	if (check < start || check > end)
		return (-1);
	if (cmp < 0)
		return (searchPriceHelper(arts, start, check - 1, start + ((check - start) / 2), name));
	else if (cmp > 0)
		return (searchPriceHelper(arts, check + 1, end, check + ((end - check) / 2), name));
	else
		return (arts[check]->price);
}

int searchPrice(struct s_art **arts, int n, char *name) {
	return (searchPriceHelper(arts, 0, n - 1, n/2, name));
}
