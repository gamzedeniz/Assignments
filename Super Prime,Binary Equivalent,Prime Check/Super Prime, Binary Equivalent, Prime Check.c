#include <stdio.h>
#include <math.h>
char f0(void);
int f1(void);
int f2(int x); // return number of digits of its binary equivalent
int f3(int a, int b); //return binary equivalent
int f4(int a); //super prime check
int f5(int a); //prime  check
int f6(int x); //sum
void f7(int x);

int main(void)
{
	int x;
	char ch;
	ch = f0();
	while (ch != 'Q') //user might want to quit at the beginning
	{
		x = f1();                
		switch (ch) //Assuming the user is clever enough to not to input an invalid character
		{
		case 'S':
			if (f4(x) == 1)
				printf("%d is a super prime.\n", x);
			else
				printf("%d is not a super prime.\n", x);
			break;
		case'W':
			f7(x);
			break;
		case'B':
			printf("Binary equivalent of %d is %d\n", x, f3(x,f2(x)));
			break;
		}

		ch = f0(); //updating ch
	}

	return(0);
}

char f0(void)
{
	char ch;
	printf("Input S for super prime check , B for binary equivalent, W for weird prime check or Q to quit:");
	scanf(" %c", &ch);
	return(ch);
}

int f1(void)
{
	int x;
	do {
		printf("Input an integer:");
		scanf("%d", &x);
	} while (x < 0);
	return(x);
}

int f2(int x)
{
	int i=0;
	if (x == 0) //considering the case of x being zero
		i++;
	else
	{
		while (x > 0)
		{
			x /= 2;
			i++;//digit counter
		}
	}
	return(i);
}

int f3(int a, int b)
{

	int i,sum=0;
	for (i = 0; i <= b-1; i++)
	{
		sum += int(pow(10, i))*(a % 2); //finding binary equivalent
		a /= 2; //updating a
	}
	return(sum);
}

int f6(int x)
{
	int sum = 0;
	while (x > 0)
	{
		sum += x % 10;
		x /= 10;
	}
	return(sum);
}

int f5(int a)
{
	int i,count=0;
	for (i = 1; i <= a; i++)
	{
		if (a%i == 0) //counting each time it finds a divider
			count++; 
	}
	if (count ==2)  //for prime numbers dividers can only be itself and 1
		return(1);
	else
		return(0);
}

int f4(int a)                 
{
	int flag = 0;
	if (f5(a) == 1) //checking if the number is a prime number
	{
		flag = 1;
		while (a / 10 > 9 && flag==1)  //keep checking until it is a 1 digit number and a prime number
		{
			if (f5(f6(a)) == 1)  //checking if sum of its digits is a prime number
				a = f6(a);		//updating a		
			else
				flag = 0;		//updating flag, there is no need to keep going once flag is zero					

		}

	}
	return(flag);
}

void f7(int x)
{
	int a,i,c=1,flag=0; //flag will be my key to continue; when number is prime, flag is 1
	if (f5(x) == 1)
	{
		flag = 1;
		a = x;
		while (a / 10 > 0)
		{
			a /= 10;
			c++; //counting number of its digits
		}
		
		
		a = x;
		for (i = c - 1; i >= 1 && flag == 1; i--) //stop when flag is zero
		{
			a %= int(pow(10, i));  //removing from left
			if (f5(a) == 0)
				flag = 0;    
		}
		
		if (flag == 1) //start removing from right when flag is still one
		{
			a = x;
			for (i = 1; i <= c - 1 && flag == 1; i++)
			{
				a /= 10;  //removing from right
				if (f5(a) == 0)
					flag = 0;
			}
		}
		
	}

	if (flag == 1)
		printf("%d is a weird prime.\n", x);
	else
		printf("%d is not a weird prime.\n", x);

}
