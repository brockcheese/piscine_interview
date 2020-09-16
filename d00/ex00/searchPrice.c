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

//searches in the array the price of a work of art, given its name as parameter

int	searchPrice(struct s_art **arts, char *name) {
	int i; //incrementor

	i = -1; //initializing i
	while(arts[++i]) {
		//for each item in the array check if the item matches the name
		if (strcmp(arts[i]->name, name) == 0)
			return (arts[i]->price); //return the price
	}
	return (-1); //otherwise return -1
}
