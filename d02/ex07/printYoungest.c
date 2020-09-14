/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printYoungest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:23:43 by bpace             #+#    #+#             */
/*   Updated: 2020/03/05 02:08:11 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int printYoungestHelper(int *ages, int start, int end) {
	int m, l, r, max;

	if (end < start)
		return (-1);
	m = (end + start) / 2;
	max = ages[m];
	l = printYoungestHelper(ages, start, m - 1);
	r = printYoungestHelper(ages, m + 1, end);
	if (l != -1 && l < max)
		max = l;
	if (r != -1 && r < max)
		max = r;
	return (max);
}

void printYoungest(int *ages, int length) {
	printf("Youngest : %d\n", printYoungestHelper(ages, 0, length - 1));
}
