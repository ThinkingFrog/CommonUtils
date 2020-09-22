#pragma once

//main tree structure
typedef struct {
	int val;
	struct tree_t* parent;
	struct tree_t* left;
	struct tree_t* right;
}tree_t;

//enum type to track last move direction in the tree
typedef enum {
	None,
	L,
	R,
	U
}move;

//list struct to create a queue based on it
typedef struct {
	tree_t* data;
	struct list_t* next;
}list_t;

//supporting operations with tree
void TreeNavigationToLess(tree_t** head, move* last_move, tree_t** parent);
void TreeNavigationToMore(tree_t** head, tree_t** parent);
void NodeInsertion(tree_t** head, tree_t** parent, move last_move);
void FreeNode(tree_t** head, tree_t** parent);
unsigned GetMaxDepth(tree_t* head);

//main operations with tree
void DeleteNode(tree_t** head);
void AddNode(tree_t** head);
void PrintTree(tree_t* head);
void DestroyTree(tree_t** head);

//queue operations
tree_t* QueuePop(list_t** queue);
void QueuePush(list_t** queue, tree_t* val);