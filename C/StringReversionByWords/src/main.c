#include <stdio.h> 
#include <stdlib.h>
#pragma warning (disable: 4996) 

int IsAlpha(char c)				//Проверка подходит ли символ
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
		return 1;
	else
		return 0;
}

void RotateWords(char string[])
{
	int n = 0, i, k = 0, a, lng1 = 0, lng2 = 0, end1, end2, b;
	char tmp;
	while (string[n] != 0)          //вычисляем длину введенной строки
		n++;
	if (n > 99)						//если строка больше 100 символов, обрезаем
	{
		printf("Edited line: ");
		puts(string);
		printf("\n");
	}
	for (i = 0; i < n + 1; i++)									//вычисление длин слов и координат их концов
	{
		if (IsAlpha(string[i]))
		{
			k++;
		}
		else if (k > 0)
		{
			if (lng1 > 0)
			{
				lng2 = k;
				end2 = i;
			}
			else
			{
				lng1 = k;
				end1 = i;
				k = 0;
			}

			if (lng2 > 0 && lng1 > 0)											//побуквенное перетаскивание слов
			{
				for (a = 0; a < lng1; a++)
				{
					for (b = end1 - lng1; b < end2 - 1; b++)
					{
						tmp = string[b];
						string[b] = string[b + 1];
						string[b + 1] = tmp;
					}
				}
				for (a = 0; a < lng2; a++)
				{
					for (b = end2 - lng1 - 1; b > end1 - lng1; b--)
					{
						tmp = string[b];
						string[b] = string[b - 1];
						string[b - 1] = tmp;
					}
				}
				end1 = end2;
				k = 0;
			}
		}
	}
}

int main(void)
{
	char string[100];
	printf("Input line:  ");
	gets(string);
	RotateWords(string);
	if (string[0] == 0)
		return 0;
	printf("New line:    ");
	puts(string);
	printf("\n");
	if (string[0] != 0)
		main();
	return 0;
}