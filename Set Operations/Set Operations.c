#include <stdio.h>
void inputSets(int b[][10], int size);
void swapSets(int a[][10], int size, int index1, int index2);
void findIntersection(int a[][10], int size, int c1, int c2, int z[], int *size2);
void shiftSets(int a[][10], int size);
void findUnion(int a[][10], int size, int c1, int c2, int *size2, int z[]);
int main(void)
{
	int choice, x[10][10],a,b,z[20],s1,i,j;
	do {
		printf("0. Input sets\n1. Swap sets\n2. Find intersection\n3. Shift sets\n4. Find Union\n5. Quit\n");
		printf("Enter your choice (0, 1,2,3,4,5):");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			inputSets(x, 10);
			printf("***********\n");
			break;
		case 1:
			printf("Input set columns to swap:");
			scanf("%d %d", &a, &b);
			swapSets(x, 10, a - 1, b - 1);
			printf("Set %d and set %d swapped.\n", a, b);
			printf("***********\n");
			break;
		case 2:
			printf("Input set columns to compare: ");
			scanf("%d %d", &a, &b);
			findIntersection(x, 10, a - 1, b - 1, z, &s1);
			printf("Intersection array:");
			for (i = 0; i < s1; i++)
				printf("%d ", z[i]);
			printf("\n");
			printf("***********\n");
			break;
		case 3:
			shiftSets(x, 10);
			printf("New array:\n");
			for (i = 0; i < 10; i++)
			{
				for (j = 0; j < 10; j++)
					printf("%d ", x[i][j]);
				printf("\n");
			}
			printf("\n");
			printf("***********\n");
			break;
		case 4:
			printf("Input set columns to unite: ");
			scanf("%d %d", &a, &b);
			findUnion(x, 10, a - 1, b - 1, &s1, z);
			printf("Union of two sets:");
			for (i = 0; i < s1; i++)
				printf("%d ", z[i]);
			printf("\n");
			printf("***********\n");
			break;
		case 5:
			printf("Bye");
			break;
		default:
			printf("Invalid input.\n");
			printf("***********\n");
		}
	} while (choice != 5);
	return(0);
}

void inputSets(int b[][10], int size)
{
	int i,j;
	for (i = 0; i < 10; i++)
	{
		printf("Enter 10 integers for set %d: ", i + 1);
		for (j = 0; j < size; j++)
			scanf("%d", &b[j][i]);
	}
		
}

void swapSets(int a[][10], int size, int index1, int index2)
{
	int i,temp;
	for (i = 0; i < size; i++)
	{
		temp = a[i][index1];
		a[i][index1] = a[i][index2];
		a[i][index2] = temp;
	}
}

void findIntersection(int a[][10], int size, int c1, int c2, int z[], int *size2)
{
	int i,k=0,j,count=0,m;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (a[i][c1] == a[j][c2])
				z[k++] = a[i][c1];
		}
	}

	for (i = 0; i < k; i++)     //If user used the same number more than once in the same column and that number is in the intersection set, I am deleting it from the set leaving only the first index I see the number in as the holder of that number so that the output will include only one of them
	{

		for (j = i + 1; j < k - count; j++)
		{
			if (z[i] == z[j])
			{
				count++;
				for (m = j; m < k - count; m++)
					z[m] = z[m + 1];
				j--;
			}

		}
	}
	*size2 = k-count;
}

void shiftSets(int a[][10], int size)
{
	int n, i, j=0, temp[10][10],k;
	printf("Enter how many times the columns will be shifted to the right:");
	scanf("%d", &n);
	if (n > 10)
		n %= 10;
	for (i = 10 - n; i < 10; i++)  //storing the last columns 
		shift edilecek sütun sayýsý kadar son sütunlarý bir yerde tutuyorum
	{
		for (k = 0; k < size; k++)
			temp[k][j] = a[k][i];  
		j++;
	}

	for (i = 10 - n - 1; i >= 0; i--)
	{
		for (k = 0; k < size; k++)
			a[k][i + n] = a[k][i];
	}

	for (j = 0; j < n; j++)  //adding the cloumns that I stored
	{
		for (k = 0; k < size; k++)
			a[k][j] = temp[k][j];
	}
}

void findUnion(int a[][10], int size, int c1, int c2, int *size2, int z[])
{
	int i, k=0,j,m,count=0;
	for (i = 0; i < size; i++)  //storing the first set into union set
			z[k++] = a[i][c1];	

	for (i = 0; i < size; i++)  //adding the second set to the union set
			z[k++] = a[i][c2];


	for (i = 0; i < k; i++) //Checking if the user used the same number more than once
	{  //and since a number from a intersection set would be used more than once too, when I see the number again in another index, I am deleting it from the set by shifting the numbers and leaving only the first index I see the number in as the holder of that number 
		ve haliyle kesiþim kümesindeki elemanlar da birden fazla kullanýlmýþ olacaðý için o sayýnýn ilk görüldüðü index hariç gerisini siliyorum

		for (j = i + 1; j < k - count; j++)
		{
			if (z[i] == z[j])
			{
				count++;
				for (m = j; m < k - count; m++)
					z[m] = z[m + 1];
				j--;
			}

		}
	}
	*size2 = k - count;
}