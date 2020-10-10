/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 02:23:09 by bpace             #+#    #+#             */
/*   Updated: 2020/02/28 03:40:09 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//helper function to recursively find common ancestor

int findParentHelper(struct s_node *root, char *firstSpecies, char *secondSpecies, struct s_node **ans) {
	int sum; //stores value to check if search should continue

	if (root == NULL) //error checking
		return (0);
	sum = 0; //initializes sum check to 0
	if (!(strcmp(root->name, firstSpecies)) || !(strcmp(root->name, secondSpecies)))
		sum++; //if current node is either species increase the sum
	for(int i = 0; sum < 2 && root->children[i]; i++) {
		//for each child node recursively check if species can be found
		sum += findParentHelper(root->children[i], firstSpecies, secondSpecies, ans);
	}
	if (sum == 2) { //if both species were found set answer to current node
		*ans = root;
	}
	if (*ans) { //if ans already found return 3 as an exit code
		return (3);
	}
	return (sum); //return the current sum
}

//returns the first common ancestor of two species given an n-ary tree of life

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies) {
	struct s_node **ans; //pointer to value that will be returned
	struct s_node *ret; //value to be returned

	ans = malloc(sizeof(struct s_node *)); //allocates mem for return value
	*ans = NULL; //initializes answer to null
	//passes information to helper function to find answer
	findParentHelper(root, firstSpecies, secondSpecies, ans);
	ret = *ans; //set return value to stored answer
	free(ans); //free allocated memory
	return (ret); //return answer
}
