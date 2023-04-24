#include <stdio.h>
#include <stdlib.h>
#define STACK_MAX_SIZE 100

typedef char element;

typedef struct
{
	element data[STACK_MAX_SIZE];
	int top;
} StackType;

void init_stack(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top == (STACK_MAX_SIZE - 1));
}

void push(StackType* s, element ch)
{
	if (is_full(s))
	{
		fprintf(stderr, "Error : Full\n");
		return;
	}
	else s->data[++(s->top)] = ch;
}

element pop(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "Error : Empty\n");
		return;
	}
	else return s->data[(s->top)--];
}

int check_palin(char s[])
{
	int i = 0, j = 0;
	StackType stack;
	init_stack(&stack);

	while(s[i] != NULL)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (is_full(&stack))
			{
				printf("Error : Full\n");
				return 0;
			}
			push(&stack, s[i]);
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			if (is_full(&stack))
			{
				printf("Error : Full\n");
				return 0;
			}
			char ch = s[i] + ('a' - 'A');
			push(&stack, ch);
		}
		i++;
	}
	i = 0;
	while (s[i + j] != NULL)
	{
		if (s[i + j] >= 'a' && s[i + j] <= 'z' && s[i + j] >= 'A' && s[i + j] <= 'Z')
		{
			if (s[i + j] >= 'a' && s[i + j] <= 'z')
			{
				if (pop(&stack) != s[i + j]) return 0;
			}
			else if (s[i + j] >= 'A' && s[i + j] <= 'Z')
			{
				char a = s[i] + ('a' - 'A');
				if (pop(&stack) != a) return 0;
			}
			i++;
		}
		else j++;
	}
	if (!is_empty) printf("Error : Program Error\n");
	return 1;
}

int main()
{
	char s[STACK_MAX_SIZE] = { NULL };

	printf("Enter String : ");
	gets_s(s, sizeof(s));
	if (check_palin(s) == 1) printf("It's Palindrome\n");
	else printf("It's not Palindrome\n");
	return 0;
}