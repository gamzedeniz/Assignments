#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct port
{
	char name[100], type, category;
	double price;
	int num;
};

struct con
{
	char name1[100];
	struct port a[10];
	int nump;
};
void readData(struct con x[])
{
	int k = 0, j, i, flag = -1;
	char* token, s1[150];
	FILE* fp;
	for (i = 0; i < 5; i++)
		x[i].nump = 1;
	fp = fopen("ABC.txt", "r");
	while (!feof(fp))
	{
		fgets(s1, sizeof(s1), fp);
		token = strtok(s1, "/");
		if (k != 0)
		{
			for (j = 0; j < k; j++)
			{
				if (strcmp(x[j].name1, token) == 0)
				{
					flag = k;
					k = j;
					x[k].nump++;
				}
			}
		}
		i = x[k].nump;
		strcpy(x[k].name1, token);
		token = strtok(NULL, "/");
		strcpy(x[k].a[i - 1].name, token);
		token = strtok(NULL, "/");
		x[k].a[i - 1].type = *token;
		token = strtok(NULL, "/");
		x[k].a[i - 1].category = *token;
		token = strtok(NULL, "/");
		x[k].a[i - 1].price = atof(token);
		token = strtok(NULL, "/");
		x[k].a[i - 1].num = atoi(token);
		if (flag != -1)
		{
			k = flag;
			flag = -1;
			k--;
		}
		k++;
	}
	fclose(fp);
}
struct port findPortfolio(struct con a[]) 
{
	char con[100], port[100];
	int i, j, keep1, keep2;
	printf("Input consultant name: ");
	gets(con);
	printf("Input portfolio name: ");
	gets(port);
	for (i = 0; i < 5; i++)
	{
		if (strcmp(a[i].name1, con) == 0)
		{
			for (j = 0; j < a[i].nump; j++)
			{
				if (strcmp(a[i].a[j].name, port) == 0)
				{
					keep2 = j;
					keep1 = i;
				}
			}
		}
	}
	return(a[keep1].a[keep2]);
}

void insertPortfolio(struct con a[], struct port *p) 
{
	char con[100];
	int i,keep,j;
	printf("Input consultant name: ");
	gets(con);
	for (i = 0; i < 5; i++)
	{
		if (strcmp(a[i].name1, con) == 0)
		{
			keep = i;
		}
	}
	j = a[keep].nump;
	printf("Portfolio's name: ");
	gets(a[keep].a[j].name);
	printf("Portfolio's type: ");
	scanf("%c", &(a[keep].a[j].type));
	printf("Portfolio's category: ");
	scanf(" %c", &(a[keep].a[j].category));
	printf("Portfolio's price: ");
	scanf("%lf", &(a[keep].a[j].price));
	printf("Portfolio's number of visitors: ");
	scanf("%d", &(a[keep].a[j].num));
	a[keep].nump++;
	//portfolio'yu deðil de portfolio information'ý döndürün dendiði için pointer kullandým
	strcpy((*p).name, a[keep].a[j].name);
	(*p).type = a[keep].a[j].type;
	(*p).category = a[keep].a[j].category;
	(*p).price = a[keep].a[j].price;
	(*p).num = a[keep].a[j].num;
}

void printConsultantPortfolioList(struct con a[]) 
{
	char con[100];
	int i, keep=-1, j;
	printf("Input consultant name: ");
	gets(con);
	for (i = 0; i < 5; i++)
	{
		if (strcmp(a[i].name1, con) == 0)
		{
			keep = i;
		}
	}
	if (keep != -1)
	{
		for (j = 0; j < a[keep].nump; j++)
		{
			printf("Portfolio %d: \n", j + 1);
			printf("Portfolio's name: ");
			puts(a[keep].a[j].name);
			printf("Portfolio's type: ");
			if (a[keep].a[j].type == 'R')
				printf("Rental\n");
			else
				printf("Sale\n");
			printf("Portfolio's category: ");
			if (a[keep].a[j].category == 'B')
				printf("Building\n");
			else if (a[keep].a[j].category == 'H')
				printf("House\n");
			else
				printf("Store\n");
			printf("Portfolio's price: %.2lf\nPortfolio's number of visitors: %d\n\n", a[keep].a[j].price, a[keep].a[j].num);
		}
	}
	else
		printf("Such consultant does not exist.\n");
}

void printPortfolio(struct con a[]) 
{
	char p;
	int i, keep, j,flag=1;
	printf("Input portfolio category(B for a building, H for a house, S for a store): ");
	scanf("%c",&p);
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < a[i].nump; j++)
		{
			if (p == a[i].a[j].category)
			{
				flag = 0;
				printf("Portfolio's name: ");
				puts(a[i].a[j].name);
				printf("Portfolio's type: ");
				if (a[i].a[j].type == 'R')
					printf("Rental\n");
				else
					printf("Sale\n");
				printf("Portfolio's category: ");
				if (a[i].a[j].category == 'B')
					printf("Building\n");
				else if (a[i].a[j].category == 'H')
					printf("House\n");
				else
					printf("Store\n");
				printf("Portfolio's price: %.2lf\nPortfolio's number of visitors: %d\n\n", a[i].a[j].price, a[i].a[j].num);
			}
		}
	}
	if (flag == 1)
		printf("Such portfolio does not exist.\n");
}

void sortPortfoliosP(struct port b[], int size)
{
	struct port keep;
	int i, j,hold,flag=0;
	double max;
	for (i = 0; i < size; i++)
	{
		max = b[i].price;
		for (j = i + 1; j < size; j++)
		{
			if (b[j].price > max)
			{
				max = b[j].price;
				hold = j;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			keep = b[i];
			b[i] = b[hold];
			b[hold] = keep;
		}
		flag = 0;
	}
}

void findMostEXpensivePortfolio(struct con a[], struct port *ex)
{
	char con[100];
	int i, keep1=0;
	printf("Input consultant name: ");
	gets(con);
	for (i = 0; i < 5; i++)
	{
		if (strcmp(a[i].name1, con) == 0)
			keep1 = i;
	}
	sortPortfoliosP(a[keep1].a, a[keep1].nump); //price'ý azalan sýrayla sýraladým port.larý
	//portfolio deðil de portfolio information'i döndürün dendiði için pointer kullandým
	strcpy( (*ex).name ,a[keep1].a[0].name);
	(*ex).type=a[keep1].a[0].type;
	(*ex).category = a[keep1].a[0].category;
	(*ex).price= a[keep1].a[0].price;
	(*ex).num = a[keep1].a[0].num;

}

void outFile(struct con a[])
{
	int i, j;
	FILE* fout;
	fout = fopen("output.txt", "w");
	for (i = 0; i < 5; i++)
	{
		fprintf(fout, "Consultant: %s\n", a[i].name1);
		for (j = 0; j < a[i].nump; j++)
		{

			fprintf(fout,"Portfolio %d: Name: ",j+1);
			fprintf(fout, "%s - ", a[i].a[j].name);
			fprintf(fout,"Type: ");
			if (a[i].a[j].type == 'R')
				fprintf(fout,"Rental - ");
			else
				fprintf(fout,"Sale - ");
			fprintf(fout,"Category: ");
			if (a[i].a[j].category == 'B')
				fprintf(fout,"Building - ");
			else if (a[i].a[j].category == 'H')
				fprintf(fout,"House - ");
			else
				fprintf(fout,"Store - ");
			fprintf(fout,"Price: %d - Visitors:%d\n", (int)a[i].a[j].price, a[i].a[j].num);
			
		}
	}
	fclose(fout);
}

int main(void)
{
	char s;
	int ch,i,j,hold,flag=0,k;
	double max;
	struct con g[5];
	struct port f,keep;
	printf("Choose 1,2,3,4,5, 6, 7, 8:\n1. Read Portfolio Data\n2. Find portfolio\n3. Insert portfolio\n4. Print List of Consultant's portfolio\n5. Print List of  specific portfolio category\n6. Sort portfolios based on number of visitors\n7. Find most expensive portfolio of a consultant\n8. Quit\n");
	scanf("%d", &ch);
	scanf("%c", &s); //boslugu strýng olarak alamasýn diye
	do {
		switch (ch)
		{
		case 1:
			readData(g);
			break;
		case 2:                              
			f= findPortfolio(g);
			printf("Portfolio's name: ");
			puts(f.name);
			printf("Portfolio's type: ");
			if (f.type == 'R')
				printf("Rental\n");
			else
				printf("Sale\n");
			printf("Portfolio's category: ");
			if (f.category == 'B')
				printf("Building\n");
			else if(f.category== 'H')
				printf("House\n");
			else
				printf("Store\n");
			printf("Portfolio's price: %.2lf\nPortfolio's number of visitors: %d\n\n",f.price,f.num);
			break;
		case 3:
			insertPortfolio(g, &f);
			break;
		case 4:
			printConsultantPortfolioList(g);
			break;
		case 5:
			printPortfolio(g);
			break;
		case 6:
			for (k = 0; k < 5; k++) //azalan sýrayla sýraladým ziyaretcileri
			{
				for (i = 0; i < g[k].nump; i++)
				{
					max = g[k].a[i].num;
					for (j = i + 1; j < g[k].nump; j++)
					{
						if (g[k].a[j].num > max)
						{
							max = g[k].a[j].num;
							hold = j;
							flag = 1;
						}
					}
					if (flag == 1)
					{
						keep = g[k].a[i];
						g[k].a[i] = g[k].a[hold];
						g[k].a[hold] = keep;
					}
					flag = 0;
				}
			}
			break;
		case 7: 
			findMostEXpensivePortfolio(g, &f); //soruda parametre olarak demese de portfolio deðil de port. information döndürmemiz istendiði için port. array'inin bir elemanýný döndürmek yerine o port. infosunu döndürmek için pointer kullandým
			printf("The most expensive portfolio's information:\nPortfolio's name: ");
			puts(f.name);
			printf("Portfolio's type: ");
			if (f.type == 'R')
				printf("Rental\n");
			else
				printf("Sale\n");
			printf("Portfolio's category: ");
			if (f.category == 'B')
				printf("Building\n");
			else if (f.category == 'H')
				printf("House\n");
			else
				printf("Store\n");
			printf("Portfolio's price: %.2lf\nPortfolio's number of visitors: %d\n\n", f.price, f.num);
			break;
		}
		printf("Choose 1,2,3,4,5, 6, 7, 8:\n1. Read Portfolio Data\n2. Find portfolio\n3. Insert portfolio\n4. Print List of Consultant’s portfolio\n5. Print List of  specific portfolio category\n6. Sort portfolios based on number of visitors\n7. Find most expensive portfolio of a consultant\n8. Quit\n");
		scanf("%d", &ch);
		scanf("%c", &s); //boslugu strýng olarak alamasýn diye
	} while (ch != 8);
	outFile(g);
	return(0);
}
