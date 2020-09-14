/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertMonkey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:23:15 by bpace             #+#    #+#             */
/*   Updated: 2020/02/28 19:39:53 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_qnode {
	struct s_node *node;
	struct s_qnode *next;
};

struct s_queue {
  	struct s_qnode *first;
	struct s_qnode *last;
};

struct s_queue *queueInit(void) {
	struct s_queue *ans;

	ans = malloc(sizeof(struct s_queue));
	ans->first = NULL;
	ans->last = NULL;
	return (ans);
}

struct s_node *dequeue(struct s_queue *queue) {
	struct s_qnode *item;
	struct s_node *ans;

	item = queue->first;
	if (item == NULL)
		return (NULL);
	queue->first = item->next;
	if (queue->first == NULL)
		queue->last = NULL;
	ans = item->node;
	free(item);
	return (ans);
}

void enqueue(struct s_queue *queue, struct s_node *message) {
	struct s_qnode *newitem;

	newitem = malloc(sizeof(struct s_node));
	newitem->node = message;
	newitem->next = NULL;
	if (queue->last == NULL) {
		queue->first = newitem;
	}
	else
		queue->last->next = newitem;
	queue->last = newitem;
}

struct s_node *peek(struct s_queue *queue) {
	if (queue->first == NULL)
		return (NULL);
	return(queue->first->node);
}

int isEmpty(struct s_queue *queue) {
	if (queue->first == NULL)
		return (1);
	return (0);
}

void insertMonkeyHelper(struct s_node *monkey, struct s_queue *treeq) {
	struct s_node *temp;

	while (!isEmpty(treeq)) {
		temp = dequeue(treeq);
		if (!(temp->left)) {
			temp->left = monkey;
			return ;
		}
		else
			enqueue(treeq, temp->left);
		if (!(temp->right)) {
			temp->right = monkey;
			return ;
		}
		else
			enqueue(treeq, temp->right);
	}
}

struct s_node *heapify(struct s_node *root) {
	struct s_node *temp;

	if (root) {
		temp = root;
		root->left = heapify(root->left);
		root->right = heapify(root->right);
		if (root->left && root->left->value > root->value) {
			temp = root->right;
			root->right = root->left->right;
			root->left->right = temp;
			temp = root->left;
			root->left = temp->left;
			temp->left = root;
		}
		if (root->right && root->right->value > root->value) {
			temp = root->left;
			root->left = root->right->left;
			root->right->left = temp;
			temp = root->right;
			root->right = temp->right;
			temp->right = root;
		}
		return(temp);
	}
	return (NULL);
}

void insertMonkey(struct s_node **root, struct s_node *monkey) {
	struct s_queue *treeq;
	treeq = queueInit();
	enqueue(treeq, *root);
	insertMonkeyHelper(monkey, treeq);
	while(!isEmpty(treeq))
		dequeue(treeq);
	free(treeq);
	*root = heapify(*root);
}
