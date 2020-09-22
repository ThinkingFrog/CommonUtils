#include <stdio.h>
#pragma warning(disable:4996)

int main(void)
{
	int i = 2, cnt = 1, num = 1;
	long n, tmp;
	scanf("%li", &n);
	if (n == 1)
	{
		printf("%li^1\n", n);
		return 0;
	}
	else
	{
		tmp = n;
		while (tmp > 1 && i * i < n)
		{
			if (tmp % i == 0)
			{
				cnt = 1;
				if (num != 1)
					printf(" * ");
				printf("%i", i);
				tmp /= i;
				while (tmp % i == 0)
				{
					tmp /= i;
					cnt++;
				}
				printf("^%i", cnt);
				num++;
			}
			if (i >= 3)
				i += 2;
			else
				i++;
		}
		if (i * i >= n && tmp > 1)
			if (num != 1)
				printf(" * %li^1", tmp);
			else
				printf("%li^1", tmp);
		printf("\n");
	}
	return 0;
}