/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:08:40 by bpace             #+#    #+#             */
/*   Updated: 2020/03/04 22:06:25 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(char *c1, char *c2) {
	char	c;

	c = *c1;
	*c1 = *c2;
	*c2 = c;
}

void	print_permutations_helper(char *str, int curr, int len) {
	int	i;

	if (curr == len) {
		printf("%s\n", str);
	}
	else {
		for (i = curr; i <= len; i++) {
			swap((str + curr), (str + i));
			print_permutations_helper(str, curr + 1, len);
			swap((str + curr), (str + i));
		}
	}
}

void	printPermutations(char *str) {
	if (str)
		print_permutations_helper(str, 0, strlen(str) - 1);
}
