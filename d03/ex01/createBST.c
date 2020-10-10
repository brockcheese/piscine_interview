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

//helper function for binary recursion

struct s_node *createNode(int *arr, int start, int end) {
	if (start > end) //exit condition
		return (NULL);
	struct s_node *ans; //node to be returned

	int m = (start + end) / 2; //stores middle index of array
	ans = malloc(sizeof(struct s_node)); //creates parent node to return
	ans->value = arr[m]; //stores value of current index
	//recursively creates left side of tree
	ans->left = createNode(arr, start, m - 1);
	//recursively creates right side of tree
	ans->right = createNode(arr, m + 1, end);
	return (ans); //returns parent node
}

//returns a balanced binary search tree given an array of integers

struct s_node *createBST(int *arr, int n) {
	return (createNode(arr, 0, n - 1));
}
