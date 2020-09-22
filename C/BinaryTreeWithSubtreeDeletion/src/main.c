#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <math.h>
#include <time.h>
#pragma warning (disable : 4996)

#define SIZE 8

typedef struct {
	int val;
	struct tree_t* left;
	struct tree_t* right;
}tree_t;

int j = 0, * A, depth, width;

int Max(int a, int b) {
	return a > b ? a : b;
}

int GetDepth(tree_t* t) {
	if (t == NULL)
		return 0;
	return Max(GetDepth((tree_t*)t->left), GetDepth((tree_t*)t->right)) + 1;
}

tree_t* AddNode(tree_t* top, int val) {	//adding node to tree with given value
	if (top == NULL) {
		top = (tree_t*)malloc(sizeof(tree_t));
		top->val = val;
		top->left = NULL;
		top->right = NULL;
	}
	else {
		if (val > top->val)
			top->right = AddNode((tree_t*)top->right, val);
		else
			top->left = AddNode((tree_t*)top->left, val);
	}
	return top;
}

tree_t* CreateTree(int size) {		//create tree with randomized nodes
	int i;
	tree_t* res = NULL;
	for (i = 0; i < size; i++)
		res = AddNode(res, rand() % 100);
	return res;
}

void DestroyTree(tree_t* top) {	//destroy tree or a subtree
	if (top != NULL) {
		DestroyTree((tree_t*)top->left);
		DestroyTree((tree_t*)top->right);
		free(top);
	}
}

tree_t* SearchTree(tree_t* top, int val) {		//search for a node with special value
	while (val != top->val) {
		if (val > top->val)
			top = (tree_t*)top->right;
		else
			top = (tree_t*)top->left;
	}
	return top;
}

tree_t* SearchPrev(tree_t* top, tree_t* tmp) {		//search for a parent of a given node
	while ((tree_t*)top->right != tmp && (tree_t*)top->left != tmp) {
		if (tmp->val > top->val)
			top = (tree_t*)top->right;
		else
			top = (tree_t*)top->left;
	}
	return top;
}

void DeleteNode(tree_t** tree) {	//Delete a subtree of a node with given value
	int key = 0;
	tree_t* tmp, * tmp2 = NULL;
	printf("\nInput key value: ");
	scanf("%i", &key);
	tmp = SearchTree(*tree, key);
	if (tmp != *tree)
		tmp2 = SearchPrev(*tree, tmp);
	DestroyTree(tmp);
	if (tmp2 != NULL)
		if ((tree_t*)tmp2->right == tmp)
			tmp2->right = NULL;
		else
			tmp2->left = NULL;
	else
		*tree = NULL;
}

void FillTreeMatrix(tree_t* tree, int i) {
	if (tree != NULL) {
		FillTreeMatrix(tree->left, i + 1);
		A[i * width + j] = tree->val;
		j++;
		FillTreeMatrix(tree->right, i + 1);
	}
}

void PrintTreeMatrix(tree_t* tree) {
	int i, j;
	depth = GetDepth(tree), width = (int)pow(2, depth);
	A = (int*)malloc(sizeof(int) * depth * width);
	for (i = 0; i < depth; i++) {
		for (j = 0; j < width; j++)
			A[i * width + j] = -1;
	}
	FillTreeMatrix(tree, 0);
	printf(" ");
	for (i = 0; i < depth; i++) {
		for (j = 0; j < width; j++)
			if (A[i * width + j] == -1)
				printf("  ");
			else
				printf("%i", A[i * width + j]);
		printf("\n");
		if (i % 2 == 1)
			printf(" ");
	}
	free(A);
}

int main(void) {
	tree_t* tree = CreateTree(SIZE);
	PrintTreeMatrix(tree);
	DeleteNode(&tree);
	PrintTreeMatrix(tree);

	DestroyTree(tree);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
	return 0;
}
