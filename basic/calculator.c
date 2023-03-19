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

int main(void)
{
	int check, value;
	char string[30], *input;
	char multiply, divide, add, subtract;

	printf("CALCULATOR\nStart Operation\n");
	scanf("%s", string);
	input = malloc(sizeof(char) * (strlen(string) + 1));
	strcpy(input, string);
	check = _check(input);
	if (check == 0)
	{
		printf("No Operation defined\n");
		return (1);
	}
	/*
	if (check == 5)
	{
		printf("Invalid character found, EXITING!!\n");
	}
	*/
	if (check == 1)
		value = _multiply(input);
	if (check == 2)
		value = _divide(input);
	if (check == 3)
		value = _add(input);
	if( check == 4)
		value = _subtract(input);

	return (0);
}
