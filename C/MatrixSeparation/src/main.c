#include <stdio.h>
#include <crtdbg.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable : 4996)

typedef struct {
	int col, val;
	struct matrix_t* next;
}matrix_t;

void CreateMatrix(FILE* F, int size) {
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
			fprintf(F, "%i ", rand() % 10);
		fprintf(F, "\n");
	}
	fprintf(F, "\0");

	fseek(F, 0, SEEK_SET);
	printf("Matrix with size of %i successfully created\n", size);
}

int CheckSize(FILE* F) {
	char c;
	int n = 0;

	while ((c = fgetc(F)) != '\n')
		if (c != ' ')
			n++;

	fseek(F, 0, SEEK_SET);
	return n;
}

matrix_t* ReadMatrix(FILE* F, int n, int* rowIndex) {
	matrix_t* res = (matrix_t*)malloc(sizeof(matrix_t)), * top = res;
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == 0 && j == 0)
				;
			else {
				(matrix_t*)res->next = malloc(sizeof(matrix_t));
				res = (matrix_t*)res->next;
			}
			res->col = j;
			fscanf(F, "%i", &(res->val));
			res->next = NULL;
			if (j == 0)
				rowIndex[i] = res->val;
		}
	}
	rowIndex[i] = rowIndex[i - 1] + n - i + 1;

	res = top;
	printf("Matrix successfully read\n");
	return res;
}

matrix_t** DivideMatrix(matrix_t* matr, int n, int* rowIndex, int** rowIndexDiv) {
	matrix_t** res = (matrix_t**)malloc(sizeof(matrix_t*) * 4), * top = matr, * restop[4];
	int i, j, k, ki[4] = { 0 }, kj[4] = { 0 }, nk[4] = { 0 };

	for (k = 0; k < 4; k++) {
		res[k] = (matrix_t*)malloc(sizeof(matrix_t));
		restop[k] = res[k];
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {

			if (i < n / 2 && j < n / 2)
				k = 0;
			else
				if (i < n / 2 && j >= n / 2)
					k = 1;
				else
					if (i >= n / 2 && j < n / 2)
						k = 2;
					else
						if (i >= n / 2 && j >= n / 2)
							k = 3;

			if ((i == 0 && j == 0) || (i == 0 && j == n / 2) || (i == n / 2 && j == 0) || (i == n / 2 && j == n / 2))
				;
			else {
				(matrix_t*)res[k]->next = malloc(sizeof(matrix_t));
				res[k] = (matrix_t*)res[k]->next;
			}
			if (kj[k] == 0)
				rowIndexDiv[k][ki[k]] = nk[k];
			res[k]->col = kj[k]++;
			if (kj[k] >= n / 2) {
				kj[k] = 0;
				ki[k]++;
			}
			res[k]->val = matr->val;
			res[k]->next = NULL;
			matr = (matrix_t*)matr->next;
			nk[k]++;
		}
	}

	for (k = 0; k < 4; k++) {
		res[k] = restop[k];
		rowIndexDiv[k][i] = rowIndexDiv[k][i - 1] + n - i + 1;
	}
	matr = top;
	printf("Matrix successfully divided\n");
	return res;
}

void PrintMatrix(matrix_t* matr, FILE* F, int* rowIndex) {
	matrix_t* next, * top = matr;
	int n = 0, i = 1;

	while (matr != NULL) {
		fprintf(F, "%i ", matr->val);
		next = (matrix_t*)matr->next;
		if ((next != NULL) && (++n == rowIndex[i])) {
			fprintf(F, "\n");
			i++;
		}
		matr = (matrix_t*)matr->next;
	}

	fprintf(F, "\n\n");
	printf("Matrix successfully printed to file\n");
	matr = top;
}

void MatrixDestroy(matrix_t* res) {
	matrix_t* next;
	while (res != NULL) {
		next = (matrix_t*)res->next;
		free(res);
		res = next;
	}
}

int main(void) {
	FILE* F_IN, * F_OUT;
	int n, i, size, * rowIndex, ** rowIndexDiv;
	matrix_t* matr;
	matrix_t** res;
	srand((unsigned int)time(0));
	F_IN = fopen("input.txt", "w+");
	F_OUT = fopen("output.txt", "w");
	if (F_IN == NULL || F_OUT == NULL) {
		printf("Couldn't open file\n");
		return;
	}
	do {
		size = rand() % 10;
	} while (size % 2 != 0 || size <= 0);

	CreateMatrix(F_IN, size);
	n = CheckSize(F_IN);
	rowIndex = (int*)malloc(sizeof(int) * (n + 1));
	rowIndexDiv = (int**)malloc(sizeof(int) * 4);
	for (i = 0; i < 4; i++) {
		rowIndexDiv[i] = (int*)malloc(sizeof(int) * (n + 1));
	}

	matr = ReadMatrix(F_IN, n, rowIndex);
	res = DivideMatrix(matr, n, rowIndex, rowIndexDiv);
	for (i = 0; i < 4; i++)
		PrintMatrix(res[i], F_OUT, rowIndexDiv[i]);

	for (i = 0; i < 4; i++)
		MatrixDestroy(res[i]);
	MatrixDestroy(matr);
	free(res);
	free(rowIndex);
	for (i = 0; i < 4; i++)
		free(rowIndexDiv[i]);
	free(rowIndexDiv);
	fclose(F_OUT);
	fclose(F_IN);

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	return 0;
}