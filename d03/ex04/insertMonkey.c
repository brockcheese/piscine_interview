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

//struct of a queue node

struct s_qnode {
	struct s_node *node;
	struct s_qnode *next;
};

//struct of a queue

struct s_queue {
  	struct s_qnode *first;
	struct s_qnode *last;
};

//initializes a queue

struct s_queue *queueInit(void) {
	struct s_queue *ans; //queue to be returned

	ans = malloc(sizeof(struct s_queue)); //allocates memory for the queue
	ans->first = NULL; //initializes first item to NULL
	ans->last = NULL; //initializes last item to NULL
	return (ans); //return initialized queue
}

//removes the first item in the queue

struct s_node *dequeue(struct s_queue *queue) {
	struct s_qnode *item; //stores queue node to be freed
	struct s_node *ans; //stores node to be freed

	item = queue->first; //store first queue node to be feed
	if (item == NULL) //error checking if queue is empty
		return (NULL);
	queue->first = item->next; //reset first node of queue to next node
	if (queue->first == NULL) //if queue is empty set last pointer to NULL
		queue->last = NULL;
	ans = item->node; //store node to be freed
	free(item); //free queue node
	return (ans); //free data node
}

//inserts an item at the end of the queue

void enqueue(struct s_queue *queue, struct s_node *message) {
	struct s_qnode *newitem; //node to store new data

	newitem = malloc(sizeof(struct s_node)); //allocates memory for node
	newitem->node = message; //sets node to node passed
	newitem->next = NULL; //sets next node to NULL
	if (queue->last == NULL) { //if queue is empty set node as first item
		queue->first = newitem;
	}
	else //link the last node to the current node
		queue->last->next = newitem;
	queue->last = newitem; //set node as last item in queue
}

//returns the first node in a queue

struct s_node *peek(struct s_queue *queue) {
	if (queue->first == NULL) //if queue is empty return NULL
		return (NULL);
	return(queue->first->node); //return first node in queue
}

//checks if the queue is empty

int isEmpty(struct s_queue *queue) {
	if (queue->first == NULL) //return 1 if queue is empty
		return (1);
	return (0); //return 0 if queue is full
}

//inserts item into tree by queuing each node in level order

void insertMonkeyHelper(struct s_node *monkey, struct s_queue *treeq) {
	struct s_node *temp; //node to store next node at level order

	while (!isEmpty(treeq)) {
		temp = dequeue(treeq); //sets temporary node as next node
		if (!(temp->left)) { //insert node if no left child found
			temp->left = monkey;
			return ;
		}
		else //inserts left child in the queue to be accessed later
			enqueue(treeq, temp->left);
		if (!(temp->right)) { //insert node if no right child found
			temp->right = monkey;
			return ;
		}
		else //inserts right child in the queue to be accessed later
			enqueue(treeq, temp->right);
	}
}

//transforms a balanced binary tree into a max-heap

struct s_node *heapify(struct s_node *root) {
	struct s_node *temp; //stores temporary node for swapping

	if (root) {
		temp = root; //initialize node to parent node
		//recursively heapify left side of tree
		root->left = heapify(root->left);
		//recursively heapify right side of tree
		root->right = heapify(root->right);
		//if left child greater than parent value swap nodes
		if (root->left && root->left->value > root->value) {
			temp = root->right;
			root->right = root->left->right;
			root->left->right = temp;
			temp = root->left;
			root->left = temp->left;
			temp->left = root;
		}
		//if right child greater than parent value swap nodes
		if (root->right && root->right->value > root->value) {
			temp = root->left;
			root->left = root->right->left;
			root->right->left = temp;
			temp = root->right;
			root->right = temp->right;
			temp->right = root;
		}
		return(temp); //return new parent node
	}
	return (NULL); //return NULL if tree is empty
}

//inserts an item into a max-heap

void insertMonkey(struct s_node **root, struct s_node *monkey) {
	struct s_queue *treeq; //declares queue to store nodes
	treeq = queueInit(); //initialize queue
	enqueue(treeq, *root); //add root node to queue
	insertMonkeyHelper(monkey, treeq); //insert node into tree
	while(!isEmpty(treeq)) //remove all items in the queue
		dequeue(treeq);
	free(treeq); //free the queue
	*root = heapify(*root); //heapify the binary tree
}
