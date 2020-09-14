/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 23:23:59 by bpace             #+#    #+#             */
/*   Updated: 2020/03/10 16:08:52 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int toInt(char *bits) {
	int ans = 0;
	int b = 1;
	for(int i = 3; i >= 0; i--) {
		ans += (bits[i] - '0') * b;
		b *= 2;
	}
	return (ans);
}

char *getAnd(char *a, char *b) {
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
			b[j] = (b[j] == '1') ? '0' : '1';
		ans[k++] = (a[i++] == '1' && b[j] == '1') ? '1' : '0';
		j++;
	}
	return (ans);
}

char *getOr(char *a, char *b) {
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
			b[j] = (b[j] == '1') ? '0' : '1';
		ans[k++] = (a[i++] == '1' || b[j] == '1') ? '1' : '0';
		j++;
	}
	return (ans);
}
