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

//finds the smallest node in a binary tree

int				getmin(struct s_node *root) {
	int min; //stores return value
	int temp; //stores temporary minimum for comparison

	min = root->value; //initializes minimum to current node value
	//recursively compares current minimum with minimum of left children
	if (root->left) {
		temp = getmin(root->left);
		if (temp < min)
			min = temp;
	}
	//recursively compares current minimum with minimum of right children
	if (root->right) {
		temp = getmin(root->right);
		if (temp < min)
			min = temp;
	}
	return (min); //returns the minimum value in the tree
}

//finds the largest node in a binary tree

int				getmax(struct s_node *root) {
	int max; //stores return value
	int temp; //stores temporary maximum for comparison

	max = root->value; //initializes maximum to current node value
	//recursively compares current maximum with maximum of left children
	if (root->left) {
		temp = getmax(root->left);
		if (temp > max)
			max = temp;
	}
	//recursively compares current maximum with maximum of right children
	if (root->right) {
		temp = getmax(root->right);
		if (temp > max)
			max = temp;
	}
	return (max); //returns the maximum value in the tree
}

//finds the number of nodes in a binary tree

int				getNodes(struct s_node *root) {
	if (!root) //if there is no tree return 0
		return (0);
	//return the current node summed with all nodes on the left and right
	return (1 + getNodes(root->left) + getNodes(root->right));
}

//finds the height of a binary tree

int				getHeight(struct s_node *root) {
	if (!root) //if there is no tree return -1
		return (-1);
	int leftHeight = getHeight(root->left); //finds height of left nodes
	int rightHeight = getHeight(root->right); //finds height of right nodes
	//return the larger height plus the current node to determine height
	return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

//checks if a binary tree is a binary search tree

int				getIsBST(struct s_node *root) {
	if(!root) //if there is no tree then by default its an empty bst
		return (1);
	//if the tree is not a bst recursively then the tree is not a bst
	if (!(getIsBST(root->left)) || !(getIsBST(root->right)))
		return (0);
	//if value of left node greater than current node it is not a bst
	if (root->left && root->left->value > root->value)
		return (0);
	//if value of right node is smaller than current node its not a bst
	if (root->right && root->right->value <= root->value)
		return (0);
	return (1); //return 1 if tree is a binary search tree
}

//checks if a binary tree is balanced

int				getBalanced(struct s_node *root) {
	int lh, rh;

	if (!root) //if there is no tree then by default it is balanced
		return (1);
	//if the tree is not balanced recursively then the tree is not balanced
	if (!(getBalanced(root->left)) || !(getBalanced(root->right)))
		return (0);
	lh = getHeight(root->left); //stores height of left nodes
	rh = getHeight(root->right); //stores height of right nodes
	if (lh == rh || lh == rh + 1 || lh + 1 == rh)
		return (1); //checks if tree is balanced at current node
	return (0); //return 0 if tree not balanced
}

//returns the information related to a tree with root node passed as parameter

struct s_info getInfo(struct s_node *root) {
	struct s_info info; //declares data structure

	info.min = getmin(root); //sets smallest node on the tree
	info.max = getmax(root); //sets largest node on the tree
	info.elements = getNodes(root); //sets number of nodes on the tree
	info.height = getHeight(root); //sets the height of the tree
	info.isBST = getIsBST(root); //checks if it is a binary search tree
	info.isBalanced = getBalanced(root); //checks if tree is balanced
	return (info); //returns data
}
