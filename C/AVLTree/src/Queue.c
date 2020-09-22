#include <stdlib.h>
#include <math.h>
#include "Main.h"

//push an element to queue's end
void QueuePush(list_t** queue, tree_t* val) {
	list_t* const top = (*queue);

	//going to last element
	while ((*queue) != NULL && (*queue)->next != NULL)
		(*queue) = (list_t*)(*queue)->next;

	//inserting new element
	if (*queue != NULL) {
		(list_t*)(*queue)->next = (list_t*)malloc(sizeof(list_t));
		(*queue) = (list_t*)(*queue)->next;
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
	list_t* next = (list_t*)(*queue)->next;
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
	unsigned depth = head->key + 1, i;
	for (i = 0; pow(2, i) < depth; i++)
		;
	return i + 1;
}