/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveTheSequoia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 03:45:19 by bpace             #+#    #+#             */
/*   Updated: 2020/02/28 16:06:46 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_node *saveTheSequoiaHelper(struct s_node *root) {
	struct s_node *temp;

	if (!root)
		return (NULL);
	if (!(root->left) && !(root->right))
		return (root);
	root->left = saveTheSequoiaHelper(root->left);
	root->right = saveTheSequoiaHelper(root->right);
	temp = root;
	if (root->left && root->left->value > root->value) {
		if (root->right && root->right->value > root->left->value) {
			temp = root->left;
			root->left = root->right->left;
			root->right->left = temp;
			temp = root->right;
			root->right = temp->right;
			temp->right = root;
			temp->right = saveTheSequoiaHelper(temp->right);
		}
		else {
			temp = root->right;
			root->right = root->left->right;
			root->left->right = temp;
			temp = root->left;
			root->left = temp->left;
			temp->left = root;
			temp->left = saveTheSequoiaHelper(temp->left);
		}
	}
	else if (root->right && root->right->value > root->value) {
		temp = root->left;
		root->left = root->right->left;
		root->right->left = temp;
		temp = root->right;
		root->right = temp->right;
		temp->right = root;
		temp->right = saveTheSequoiaHelper(temp->right);
	}
	return (temp);
}

void saveTheSequoia(struct s_node **root) {
	*root = saveTheSequoiaHelper(*root);
}
