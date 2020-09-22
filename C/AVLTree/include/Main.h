#pragma once

typedef struct {
    int key;
    unsigned height;
    struct tree_t* right;
    struct tree_t* left;
}tree_t;

typedef struct {
    tree_t* data;
    struct list_t* next;
}list_t;

//queue operations
tree_t* QueuePop(list_t** queue);
void QueuePush(list_t** queue, tree_t* val);

//main tree operations
void PrintTree(tree_t* head);
tree_t* AddNode(tree_t* top, int key);
void DestroyTree(tree_t* top);
tree_t* Balance(tree_t* node);

//supporting tree operations
tree_t* InitNode(int key);
tree_t* CreateTree(int size);
unsigned GetHeight(tree_t* node);
int bfactor(tree_t* node);
void FixHeight(tree_t* node);
tree_t* RotateRight(tree_t* node);
tree_t* RotateLeft(tree_t* node);
tree_t* FindMin(tree_t* head);
tree_t* RemoveMin(tree_t* head);
tree_t* Remove(tree_t* head, int key);