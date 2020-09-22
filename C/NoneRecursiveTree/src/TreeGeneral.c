#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Main.h"

//Adding a node to a subtree with least nodes
void AddNode(tree_t** head) {

	tree_t* const top = (*head);	//constant top node pointer
	tree_t* parent = NULL;	//parent-tracking variable pointer
	move last_move = None;	//move-tracking variable

	//looking for a proper place for a new node
	while ((*head) != NULL) {
		TreeNavigationToLess(head, &last_move, &parent);
		parent->val++;
	}

	//inserting new node
	if ((*head) == NULL)
		NodeInsertion(head, &parent, last_move);

	//going back to top of the tree
	if (top != NULL)
		(*head) = top;
}

//delete one of the lowest nodes in the tree
void DeleteNode(tree_t** head) {
	tree_t* const top = (*head);	//constant top node pointer
	tree_t* parent = NULL;	//parent-tracking variable pointer

	//moving through tree to find a node to delete
	while ((*head)->left != NULL || (*head)->right != NULL) {
		TreeNavigationToMore(head, &parent);
		parent->val--;	//decrease a value of each visited node
	}

	FreeNode(head, &parent);	//deleting a designated node
	*head = top;	//returning pointer back to the top
}

//destroy tree and free all allocated memory
void DestroyTree(tree_t** head) {
	list_t* queue = NULL;
	tree_t* tmp;

	if (head == NULL)
		return;

	QueuePush(&queue, *head);

	while (queue != NULL) {

		tmp = QueuePop(&queue);

		if (tmp->left)
			QueuePush(&queue, (tree_t*)tmp->left);
		if (tmp->right)
			QueuePush(&queue, (tree_t*)tmp->right);

		FreeNode(&tmp, (tree_t**)&(tmp->parent));
	}
}

//print tree from top to bottom
void PrintTree(tree_t* head) {
	int level = 1, levelWidth = 1, i = 0, depth = GetMaxDepth(head), j;
	list_t* queue = NULL;
	tree_t* tmp;

	if (head == NULL)
		return;

	QueuePush(&queue, head);

	//whitespaces formating
	for (j = 0; j < pow(2, depth) / (levelWidth + 0.5); j++)
		printf(" ");

	while (queue != NULL) {

		tmp = QueuePop(&queue);
		printf("%i", tmp->val);

		//whitespaces formating
		for (j = 0; j < pow(2, depth) / (levelWidth + 1); j++)
			printf(" ");

		i++; //an iterator tracking amount of printed nodes in current level

		if (tmp->left)
			QueuePush(&queue, (tree_t*)tmp->left);
		if (tmp->right)
			QueuePush(&queue, (tree_t*)tmp->right);

		//whitespaces and levels formating
		if (i == levelWidth) {
			i = 0;
			printf("\n");
			for (j = 0; j < pow(2, depth) / (levelWidth + 1); j++)
				printf(" ");
			levelWidth *= 2;	//a variable tracking maximum amount of nodes on current level
			level++;	//current level tracker
		}
	}
	printf("\n");
}