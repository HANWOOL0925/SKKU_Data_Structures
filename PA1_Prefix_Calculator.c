//prefix notation으로 쓰인 식이 input으로 주어졌을 때 값을 계산하라.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

double stack[MAX_STACK_SIZE];
int top = -1;

float push(float item)
{
	if (top >= MAX_STACK_SIZE - 1) {
		printf("Stack is Full, can't add elemtent");
	}
	stack[++top] = item;
}

float pop()
{
	if (top == -1)
		printf("Stack is Empty, can't pop elemtent");
	return stack[top--];
}

int main()
{
	char input[100];
	char expr[50];
	scanf("%[^\n]", input);

	int s = strlen(input);

	int i;
	int j = 0;
	double val = 0.00;
	double op1, op2;

	for (i = 0; i <= (s - 1) / 2; i++) {
		expr[i] = input[2 * i];
	}
	expr[i + 1] = NULL;
	i = 0;

	while ((s - 1) / 2 - i != -1)
	{
		if (expr[(s - 1) / 2 - i] <= 57 && expr[(s - 1) / 2 - i] >= 48)
		{
			push(expr[(s - 1) / 2 - i] - '0');
		}

		else
		{
			op2 = pop();
			op1 = pop();
			switch (expr[(s - 1) / 2 - i]) {
				case '+': {
					val = op2 + op1;
					break;
				}
				case '-': {
					val = op2 - op1;
					break;
				}
				case '*': {
					val = op2 * op1;
					break;
				}
				case '/': {
					val = op2 / op1;
					break;
				}
			}
			push(val);
		}
		i++;
	}
	val = pop();

	printf("%.2f", val);
}