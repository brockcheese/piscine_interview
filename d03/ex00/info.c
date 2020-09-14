/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 00:36:37 by bpace             #+#    #+#             */
/*   Updated: 2020/02/28 01:33:55 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				getmin(struct s_node *root) {
	int min;
	int temp;

	min = root->value;
	if (root->left) {
		temp = getmin(root->left);
		if (temp < min)
			min = temp;
	}
	if (root->right) {
		temp = getmin(root->right);
		if (temp < min)
			min = temp;
	}
	return (min);
}

int				getmax(struct s_node *root) {
	int max;
	int temp;

	max = root->value;
	if (root->left) {
		temp = getmax(root->left);
		if (temp > max)
			max = temp;
	}
	if (root->right) {
		temp = getmax(root->right);
		if (temp > max)
			max = temp;
	}
	return (max);
}

int				getNodes(struct s_node *root) {
	if (!root)
		return (0);
	return (1 + getNodes(root->left) + getNodes(root->right));
}

int				getHeight(struct s_node *root) {
	if (!root)
		return (-1);
	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);
	return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

int				getIsBST(struct s_node *root) {
	if(!root)
		return (1);
	if (!(getIsBST(root->left)) || !(getIsBST(root->right)))
		return (0);
	if (root->left && root->left->value > root->value)
		return (0);
	if (root->right && root->right->value <= root->value)
		return (0);
	return (1);
}

int				getBalanced(struct s_node *root) {
	int lh, rh;

	if (!root)
		return (1);
	if (!(getBalanced(root->left)) || !(getBalanced(root->right)))
		return (0);
	lh = getHeight(root->left);
	rh = getHeight(root->right);
	if (lh == rh || lh == rh + 1 || lh + 1 == rh)
		return (1);
	return (0);
}

struct s_info getInfo(struct s_node *root) {
	struct s_info info;

	info.min = getmin(root);
	info.max = getmax(root);
	info.elements = getNodes(root);
	info.height = getHeight(root);
	info.isBST = getIsBST(root);
	info.isBalanced = getBalanced(root);
	return (info);
}
