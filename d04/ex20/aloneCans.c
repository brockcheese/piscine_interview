/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloneCans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:48:22 by bpace             #+#    #+#             */
/*   Updated: 2020/03/03 20:47:14 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void aloneCans(int *arr, int n) {
	int temp = 0;
	for(int i = 0; i < n; i++)
		temp ^= arr[i];
	temp = 1 << (ffs(temp) - 1);
	int ans = 0;
	int ans2 = 0;
	for(int i = 0; i < n; i++) {
		if (temp & arr[i])
			ans ^= arr[i];
		else
			ans2 ^= arr[i];
	}
	printf("%d\n%d\n", ans2, ans);
}
