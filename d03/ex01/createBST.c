/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 01:35:53 by bpace             #+#    #+#             */
/*   Updated: 2020/02/28 01:58:46 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_node *createNode(int *arr, int start, int end) {
	if (start > end)
		return (NULL);
	struct s_node *ans;

	int m = (start + end) / 2;
	ans = malloc(sizeof(struct s_node));
	ans->value = arr[m];
	ans->left = createNode(arr, start, m - 1);
	ans->right = createNode(arr, m + 1, end);
	return (ans);
}

struct s_node *createBST(int *arr, int n) {
	return (createNode(arr, 0, n - 1));
}
