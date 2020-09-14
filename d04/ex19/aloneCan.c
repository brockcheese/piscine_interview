/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloneCan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 08:35:40 by bpace             #+#    #+#             */
/*   Updated: 2020/03/03 08:38:24 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	aloneCan(int *arr, int n) {
	int ans;
	ans = 0;
	for(int i = 0; i < n; i++) {
		ans ^= arr[i];
	}
	printf("%d\n", ans);
}
