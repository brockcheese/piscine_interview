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

int findParentHelper(struct s_node *root, char *firstSpecies, char *secondSpecies, struct s_node **ans) {
	int sum;

	if (root == NULL)
		return (0);
	sum = 0;
	if (!(strcmp(root->name, firstSpecies)) || !(strcmp(root->name, secondSpecies)))
		sum++;
	for(int i = 0; sum < 2 && root->children[i]; i++) {
		sum += findParentHelper(root->children[i], firstSpecies, secondSpecies, ans);
	}
	if (sum == 2) {
		*ans = root;
	}
	if (*ans) {
		return (3);
	}
	return (sum);
}

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies) {
	struct s_node **ans;
	struct s_node *ret;

	ans = malloc(sizeof(struct s_node *));
	*ans = NULL;
	findParentHelper(root, firstSpecies, secondSpecies, ans);
	ret = *ans;
	free(ans);
	return (ret);
}
