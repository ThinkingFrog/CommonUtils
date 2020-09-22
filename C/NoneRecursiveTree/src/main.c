#include <crtdbg.h>
#include <stdio.h>
#include "Main.h"

#define SIZE 12

int main(void) {
    tree_t* head = NULL;
    unsigned i;
    for (i = 0; i < SIZE; i++)
        AddNode(&head);

    PrintTree(head);

    printf("Deleting one node\n");

    DeleteNode(&head);

    PrintTree(head);

    DestroyTree(&head);

    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
    _CrtDumpMemoryLeaks();

    return 0;
}
