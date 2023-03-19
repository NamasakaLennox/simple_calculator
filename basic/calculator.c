#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _check(char *str)
{
	int count = 0;

	while (str[count])
	{
		if (str[count] == '*')
			return (1);
		else if (str[count] == '/')
			return (2);
		else if (str[count] == '+')
			return (3);
		else if (str[count] == '-')
			return (4);
		count++;
	}
	return (0);
}

int _validity(char *str)
{
	int count = 0;

	while (str[count])
	{
		if (str[count] < 48 || str[count] > 57)
		{
			if (str[count] != '*' || str[count] != '/' || str[count] != '+' || str[count] != '-')
				return (1);
		}
		count++;
	}
	return (0);
}
int _multiply(char *str)
{
	int count = 0, setup = 0, num1, num2;
	char num_1[7], num_2[7];

	while (str[count] != '*')
	{
		num_1[setup] = str[count];
		count++;
		setup++;
	}
	num1 = atoi(num_1);
	setup = 0;
	count++; /* step to next value from the '*' sign */
	while (str[count])
	{
		num_2[setup] = str[count];
		count++;
		setup++;
	}
	num2 = atoi(num_2);
	return (num1 * num2);
}
int _divide(char *str)
{
	int count = 0, setup = 0, num1, num2;
	char num_1[7], num_2[7];

	while (str[count] != '/')
	{
		num_1[setup] = str[count];
		count++;
		setup++;
	}
	num1 = atoi(num_1);
	setup = 0;
	count++; /* step to next value from the '/' sign */
	while (str[count])
	{
		num_2[setup] = str[count];
		count++;
		setup++;
	}
	num2 = atoi(num_2);
	return (num1 / num2);
}

int _add(char *str)
{
}
int _subtract(char *str)
{
}
int main(void)
{
	int check, value, valid;
	char string[30], *input;
	char multiply, divide, add, subtract;

	printf("CALCULATOR\nStart Operation\n");
	scanf("%s", string);
	input = malloc(sizeof(char) * (strlen(string) + 1));
	strcpy(input, string);

	check = _check(input);
	valid = _validity(input); /* check for invalid character */

	if (valid == 1)
	{
		printf("Invalid character found, EXITING!!\n");
		return (1);
	}
	if (check == 0)
	{
		printf("No Operation defined\n");
		return (1);
	}

	if (check == 1)
		value = _multiply(input);
	if (check == 2)
		value = _divide(input);
	if (check == 3)
		value = _add(input);
	if( check == 4)
		value = _subtract(input);
	printf("The answer is: %d\n", value);

	return (0);
}
