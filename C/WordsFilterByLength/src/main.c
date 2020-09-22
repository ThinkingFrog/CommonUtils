#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <string.h>

typedef struct {
	int code;
	char word[100];
	struct list_t* next;
}list_t;

//freeing allocated memory for list structure
void DestroyList(list_t* res) {
	list_t* next;
	while (res != NULL) {
		next = (list_t*)res->next;
		free(res);
		res = next;
	}
}

void PrintList(list_t* res, int N) {
	list_t* top = res;
	while (res != NULL) {
		if (strlen(res->word) > (unsigned)N)
			printf("%s  %i\n", res->word, res->code);
		res = (list_t*)res->next;
	}
	res = top;
}

void PrintListEqual(list_t* res, int N) {
	list_t* top = res;
	while (res != NULL) {
		if (strlen(res->word) == (unsigned)N)
			printf("%s  %i\n", res->word, res->code);
		res = (list_t*)res->next;
	}
	res = top;
}

int main(void) {
	FILE* F;
	list_t* res = (list_t*)malloc(sizeof(list_t)), * top = res, * tmp, * tmp2;
	int N, Ne;

	//opening file
	F = fopen("input.txt", "r");
	if (F == NULL) {
		printf("Couldn't open file\n");
		return 0;
	}

	//First rotation
	fscanf(F, "%s %i", res->word, &res->code);
	res->next = NULL;
	if (res->word[0] == -51) {
		printf("File seems to be empty\n");
		return 0;
	}

	//Cycle - scanning word/code pairs with strlen sorting
	while (1) {
		res = top;

		//creating temporary list node
		tmp = (list_t*)malloc(sizeof(list_t));

		fscanf(F, "%s %i", tmp->word, &tmp->code);

		//cycle end proposition
		if (tmp->word[0] == -51)
			break;

		if (tmp->code == -842150451) {
			printf("Word/code format mismatch\n");
			return 0;
		}

		//searching for insertion point
		while (res->next != NULL && strlen(tmp->word) > strlen(res->word))
			res = (list_t*)res->next;

		//alphabetical sorting if strlen is equal
		if (strlen(tmp->word) == strlen(res->word)) {

			//inserting before ins point
			if (strcmp(tmp->word, res->word) <= 0) {

				//inserting in first position
				if (res == top) {
					(list_t*)tmp->next = res;
					top = tmp;
				}

				//inserting in a middle of list
				else {
					tmp2 = res;
					res = top;
					while ((list_t*)res->next != tmp2)
						res = (list_t*)res->next;
					tmp->next = res->next;
					(list_t*)res->next = tmp;
				}
			}

			//inserting after ins point
			else {
				tmp->next = res->next;
				(list_t*)res->next = tmp;
			}

		}
		else {

			//inserting before ins point
			if (strlen(tmp->word) < strlen(res->word)) {

				//inserting in first position
				if (res == top) {
					(list_t*)tmp->next = res;
					top = tmp;
				}

				//inserting in a middle of list
				else {
					tmp2 = res;
					res = top;
					while ((list_t*)res->next != tmp2)
						res = (list_t*)res->next;
					tmp->next = res->next;
					(list_t*)res->next = tmp;
				}
			}

			//inserting after ins point
			else {
				tmp->next = res->next;
				(list_t*)res->next = tmp;
			}
		}
	}

	//Printing words with strlen > N
	do {
		printf("Input positive number N please: ");
		scanf("%i", &N);
	} while (N < 0);
	PrintList(res, N);

	//Printing words with strlen == N
	do {
		printf("Input positive number N-equal please: ");
		scanf("%i", &Ne);
	} while (Ne < 0);
	PrintListEqual(res, Ne);

	fclose(F);
	free(tmp);
	DestroyList(res);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
	return 0;
}