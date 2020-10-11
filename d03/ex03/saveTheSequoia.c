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

//helper function to recursively transform min-heap to max-heap

struct s_node *saveTheSequoiaHelper(struct s_node *root) {
	struct s_node *temp; //temporary node for swapping

	if (!root) //if no tree exists return NULL
		return (NULL);
	if (!(root->left) && !(root->right))
		return (root); //if tree contains single node return node
	root->left = saveTheSequoiaHelper(root->left); //recurses left child
	root->right = saveTheSequoiaHelper(root->right); //recurses right child
	temp = root; //store parent node to return if already heapified
	if (root->left && root->left->value > root->value) {
		if (root->right && root->right->value > root->left->value) {
			//if right child value greater than parent swap nodes
			temp = root->left;
			root->left = root->right->left;
			root->right->left = temp;
			temp = root->right;
			root->right = temp->right;
			temp->right = root;
			temp->right = saveTheSequoiaHelper(temp->right);
		}
		else { //if left child value greater than parent swap nodes
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
		//if right child value greater than parent swap nodes
		temp = root->left;
		root->left = root->right->left;
		root->right->left = temp;
		temp = root->right;
		root->right = temp->right;
		temp->right = root;
		temp->right = saveTheSequoiaHelper(temp->right);
	}
	return (temp); //return swapped node as new parent
}

//transforms a min-heap into a max-heap

void saveTheSequoia(struct s_node **root) {
	//helper function for recursion
	*root = saveTheSequoiaHelper(*root);
}
