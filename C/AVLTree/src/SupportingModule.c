#include <stdlib.h>
#include "Main.h"

tree_t* InitNode(int key) { //initialize a node
	tree_t* head = (tree_t*)malloc(sizeof(tree_t));
	head->height = 1;
	head->key = key;
	head->right = NULL;
	head->left = NULL;
	return head;
}

tree_t* CreateTree(int size) {		//create tree with randomized nodes
	int i;
	tree_t* res = NULL;
	for (i = 0; i < size; i++)
		res = AddNode(res, rand() % 100);
	return res;
}

unsigned GetHeight(tree_t* node) {
    return node ? node->height : 0;
}

int bfactor(tree_t* node) {
    return GetHeight(node->right) - GetHeight(node->left);
}

void FixHeight(tree_t* node) {
    unsigned hleft = GetHeight(node->left);
    unsigned hright = GetHeight(node->right);
    node->height = (hleft > hright ? hleft : hright) + 1;
}

tree_t* RotateRight(tree_t* node) {
    tree_t* tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    FixHeight(node);
    FixHeight(tmp);
    return tmp;
}

tree_t* RotateLeft(tree_t* node) {
    tree_t* tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    FixHeight(node);
    FixHeight(tmp);
    return tmp;
}

tree_t* FindMin(tree_t* head) {
    return head->left ? FindMin(head->left) : head;
}

tree_t* RemoveMin(tree_t* head) {
    if (head->left == NULL)
        return head->right;
    head->left = RemoveMin(head->left);
    return Balance(head);
}