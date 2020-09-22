#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Main.h"

void DestroyTree(tree_t* top) {	//destroy tree or a subtree
    if (top != NULL) {
        DestroyTree((tree_t*)top->left);
        DestroyTree((tree_t*)top->right);
        free(top);
    }
}

tree_t* AddNode(tree_t* top, int key) { //add a node with given key
    if (!top) {
        top = InitNode(key);
        return top;
    }

    if (key < top->key)
        top->left = AddNode((tree_t*)top->left, key);
    else
        top->right = AddNode((tree_t*)top->right, key);

    return Balance(top);
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
        if (tmp != NULL)
            printf("%i", tmp->key);
        else
            printf(" ");

        //whitespaces formating
        for (j = 0; j < pow(2, depth) / (levelWidth + 1); j++)
            printf(" ");

        i++; //an iterator tracking amount of printed nodes in current level

        if (tmp == NULL)
            continue;

        if (tmp->left)
            QueuePush(&queue, (tree_t*)tmp->left);
        else
            QueuePush(&queue, NULL);
        if (tmp->right)
            QueuePush(&queue, (tree_t*)tmp->right);
        else
            QueuePush(&queue, NULL);

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


tree_t* Balance(tree_t* node) {
    FixHeight(node);

    if (bfactor(node) == 2) {
        if (bfactor(node->right) < 0)
            node->right = RotateRight(node->right);
        return RotateLeft(node);
    }

    if (bfactor(node) == -2) {
        if (bfactor(node->left) > 0)
            node->left = RotateLeft(node->left);
        return RotateRight(node);
    }

    return node;
}


tree_t* Remove(tree_t* head, int key) {
    if (!head)
        return NULL;

    if (key < head->key)
        head->left = Remove(head->left, key);

    else if (key > head->key)
        head->right = Remove(head->right, key);

    else {
        tree_t* left = head->left;
        tree_t* right = head->right;
        head->right = NULL;
        head->left = NULL;
        free(head);
        if (!right)
            return left;
        tree_t* min = FindMin(right);
        min->right = RemoveMin(right);
        min->left = left;
        return Balance(min);
    }

    return Balance(head);
}
