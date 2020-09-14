/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:13:23 by bpace             #+#    #+#             */
/*   Updated: 2020/03/04 16:38:26 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_possible_slices_helper(struct s_array *arr, int pizzasize) {
	struct s_array	*arr2;
	int				i;

	for (i = pizzasize - arr->sum; i > 0; i--) {
		arr2 = arrayClone(arr);
		arrayAppend(arr2, i);
		if (arr2->sum == pizzasize)
			arrayPrint(arr2);
		else if (arr2->sum < pizzasize)
			print_possible_slices_helper(arr2, pizzasize);
		free(arr2);
	}
}

void	printPossibleSlices(int pizzaSize) {
	struct s_array *arr = arrayInit();

	print_possible_slices_helper(arr, pizzaSize);
	free(arr);
}
