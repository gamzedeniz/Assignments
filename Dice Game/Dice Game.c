#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int point(int a, int b, int c);
void dice(int x, int y, int z);
int count = 0,dice1,dice2;
int main(void)
{
	int a, b, c, d, point1 = 0, point2 = 0, sum = 0;
	char ch;
	srand(time(NULL));
	printf("*********************\n");
	printf("Welcome to Dice Game\n");
	printf("*********************\n");
	printf("Input  P to play the game, S to display the total score, Q to Quit:");
	scanf("%c", &ch);
	while (ch !='Q')
	{
		if (ch == 'P')
		{
			do {//getting random numbers
				a = rand() % 6 + 1;
				b = rand() % 6 + 1;
				c = rand() % 6 + 1;
				d = rand() % 6 + 1;

				printf("Throw the dice for player 1: %d %d\n", a, b);
				dice1 = a + b; //getting dice sum for the player 1
				point1 += point(a, b, 1); //calling point function to calculate point of player 1

				printf("Throw the dice for player 2: %d %d\n", c, d);
				dice2 = c + d; //getting dice sum for the player 2
				point2 += point(c, d, 2); //calling point function to calculate point of player 2

				count += 2; //because in the beginning we throw dice 2 times 

			} while (dice1 != dice2 * 2);

			printf("Player 1 : %d points\nPlayer 2 : %d points\n", point1, point2);
			printf("Total of %d throws are performed.\n", count);
			if (point1 > point2)
				printf("Winner is: Player 1\n");
			else if (point1 < point2)
				printf("Winner is: Player 2\n");
			else
				printf("It's a draw");
			//updating variables for the possible next game
			count = 0;
			sum += point1 + point2;
			point1 = 0;
			point2 = 0;
		}
		else if (ch == 'S')
			printf("Total Score= %d\n", sum);
		else
			printf("Invalid input\n"); //Considering all possible inputs
		printf("Input  P to play the game, S to display the total score, Q to Quit:");
		scanf(" %c", &ch);
	}
	printf("Bye!"); 
	return(0);
}


int point(int a, int b, int c) 
{
	int i, p = 0;
	if (abs(a - b) == 4)
	{
		do {
			a = rand() % 6 + 1;
			b = rand() % 6 + 1;
			printf("Throw the dice for player %d: %d %d\n", c, a, b); //c is for mentioning the player by number
			count += 1; //throw counter
		} while (a + b <= 8);
		dice(a, b, c);
		p += (a + b) / 2;
	}
	else if ((a == 3 && b == 3) || (a == 6 && b == 6))
	{
		for (i = 1; i <= 3; i++)
		{
			a = rand() % 6 + 1;
			b = rand() % 6 + 1;
			printf("Throw the dice for player %d: %d %d\n", c, a, b);
			count += 1; //throw counter
			if (a != b)
				p += (a + b) / 2;
		}
		dice(a, b, c);
	}
	else
		p += (a + b) / 2;
	return (p); //returning the point
}

void dice(int x, int y, int z) //getting dice sum in the case of consecutive throws
{
	if (z == 1)
		dice1 = (x + y);
	else if (z == 2)
		dice2 = (x + y);
}
