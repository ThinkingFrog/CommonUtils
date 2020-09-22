#include <stdlib.h>
#include <math.h>
#include "Main.h"

//decision-making module to navigate through tree and find empty place in a subtree with least nodes
void TreeNavigationToLess(tree_t** head, move* last_move, tree_t** parent) {
	//temporal left and right children pointers
	tree_t* right = (tree_t*)(*head)->right, * left = (tree_t*)(*head)->left;

	//measuring empty children cases
	if ((right == NULL && left == NULL) || (left == NULL && right != NULL)) {	//turn left if both children don't exist or right does and left doesn't
		(*parent) = (*head);
		(*head) = left;
		*last_move = L;
		return;
	}
	else
		if (left != NULL && right == NULL) {	//turn right if left child exists and right doesn't
			(*parent) = (*head);
			(*head) = right;
			*last_move = R;
			return;
		}

	//casual turning point cases
	if (left->val <= right->val) {	//turn left if left subtree has less or equal as right nodes
		(*parent) = (*head);
		(*head) = left;
		*last_move = L;
	}
	else {	//otherwise turn right
		(*parent) = (*head);
		(*head) = right;
		*last_move = R;
	}
}

//decision-making module to navigate through tree and find an occupied place in a subtree with most nodes
void TreeNavigationToMore(tree_t** head, tree_t** parent) {
	//temporal left and right children pointers
	tree_t* right = (tree_t*)(*head)->right, * left = (tree_t*)(*head)->left;

	//measuring empty children cases
	if ((right == NULL && left == NULL) || (left != NULL && right == NULL)) {	//turn left if both children don't exist or right doesn't and left does
		(*parent) = (*head);
		(*head) = left;
		return;
	}
	else
		if (left == NULL && right != NULL) {	//turn right if right child exists and left doesn't
			(*parent) = (*head);
			(*head) = right;
			return;
		}

	//casual turning point cases
	if (left->val >= right->val) {	//turn left if left subtree has more or equal as right nodes
		(*parent) = (*head);
		(*head) = left;
	}
	else {	//otherwise turn right
		(*parent) = (*head);
		(*head) = right;
	}
}

//module to insert a new node on empty place
void NodeInsertion(tree_t** head, tree_t** parent, move last_move) {
	(*head) = (tree_t*)malloc(sizeof(tree_t));
	(*head)->left = NULL;
	(*head)->right = NULL;
	(tree_t*)(*head)->parent = *parent;
	if (*parent != NULL) {
		if (last_move == L)
			(tree_t*)(*parent)->left = (*head);
		else
			if (last_move == R)
				(tree_t*)(*parent)->right = (*head);
	}
	(*head)->val = 0;
}

//a module to free a node without consequences
void FreeNode(tree_t** head, tree_t** parent) {
	if (*parent != NULL) {
		if ((*parent)->left == *head)
			(tree_t*)(*parent)->left = NULL;
		else
			if ((*parent)->right == *head)
				(tree_t*)(*parent)->right = NULL;
	}
	free(*head);
	*head = *parent;
}

//push an element to queue's end
void QueuePush(list_t** queue, tree_t* val) {
	list_t* const top = (*queue);

	//going to last element
	while ((*queue) != NULL && (*queue)->next != NULL)
		(*queue) = (*queue)->next;

	//inserting new element
	if (*queue != NULL) {
		(*queue)->next = (list_t*)malloc(sizeof(list_t));
		(*queue) = (*queue)->next;
	}
	else
		(*queue) = (list_t*)malloc(sizeof(list_t));

	(*queue)->data = val;
	(*queue)->next = NULL;

	//going back to top
    if (top != NULL)
        (*queue) = top;
}

//pop an element from queue's beggining
tree_t* QueuePop(list_t** queue) {
	list_t* next = (*queue)->next;
	tree_t* val = NULL;

	//taking first queue element
	val = (*queue)->data;
	free(*queue);

	//moving top of the queue to the next element
	//if (next != NULL)
	*queue = next;

	return val;
}

//returns the deepest element level
unsigned GetMaxDepth(tree_t* head) {
	unsigned depth = head->val + 1, i;
	for (i = 0; pow(2, i) < depth; i++)
		;
	return i + 1;
}