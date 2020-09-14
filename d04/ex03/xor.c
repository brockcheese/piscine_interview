/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 03:18:27 by bpace             #+#    #+#             */
/*   Updated: 2020/03/03 03:22:41 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int toInt(char *bits) {
	int ans = 0;
	int b = 1;
	for(int i = 5; i >= 0; i--) {
		ans += (bits[i] - '0') * b;
		b *= 2;
	}
	return (ans);
}

char *getXor(char *a, char *b) {
	int i, j, k, an, bn;
	char *ans = malloc(sizeof(char) * 5);
	ans[4] = '\0';
	i = j = k = an = bn = 0;
	if (a[0] == '~') {
		an = 1;
		i++;
	}
	if (b[0] == '~') {
		bn = 1;
		j++;
	}
	while(a[i] && b[j]) {
		if (an == 1)
			a[i] = (a[i] == '1') ? '0' : '1';
		if (bn == 1)
			b[i] = (b[i] == '1') ? '0' : '1';
		ans[k++] = ((a[i] == '1' && b[j] == '0') || (a[i] == '0' && b[j] == '1')) ? '1' : '0';
		i++;
		j++;
	}
	return (ans);
}
