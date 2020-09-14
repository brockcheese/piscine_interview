/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutationV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:08:40 by bpace             #+#    #+#             */
/*   Updated: 2020/03/04 22:19:04 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(char *c1, char *c2) {
	char	c;

	c = *c1;
	*c1 = *c2;
	*c2 = c;
}

void	pmh(char *str, struct s_dict *d, int curr, int len) {
	int	i;

	if (curr == len && dictSearch(d, str) == -1) {
		printf("%s\n", str);
		dictInsert(d, str, 1);
	}
	else {
		for (i = curr; i <= len; i++) {
			swap((str + curr), (str + i));
			pmh(str, d, curr + 1, len);
			swap((str + curr), (str + i));
		}
	}
}

void	printUniquePermutations(char *str) {
	if (str)
		pmh(str, dictInit(strlen(str)), 0, strlen(str) - 1);
}
