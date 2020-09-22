#include <crtdbg.h>
#include <stdio.h>
#include "Main.h"
#pragma warning(disable:4996)
#define SIZE 12

int main(void) {
    int key = 0;
    tree_t* tree = CreateTree(SIZE);
    PrintTree(tree);
    printf("\n\n");
    printf("Input key value: ");
    scanf("%i", &key);
    printf("\n\n");
    tree = Remove(tree, key);
    PrintTree(tree);

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