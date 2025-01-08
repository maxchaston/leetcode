#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// 20. Valid Parentheses

/**
	 This works on my machine but not the leetcode testbench.
	 Really quite aggravating.
	 Keeps breaking in unexpected ways.

	 Rewrote in python, the fix was to set all the variables to zero at the start of the function.
	 I assume leetcode just instances the file once so they don't get zeroed on subsequent runs.
 **/

int bracket_count;
int square_count;
int curly_count;
char stack[10001]; // max size of string in question
int sp = -1; // stack pointer

char closed(char c)
{
	if (c=='(')
		return ')';
	if (c=='{')
		return '}';
	if (c=='[')
		return ']';
	return ' ';
}

void push(char c)
{
	sp++;
	stack[sp] = c;
}

char pop()
{
	char c = stack[sp];
	sp--;
	return c;
}

char peek()
{
	return stack[sp];
}

void change_count(char c)
{
	if (c=='(')
	{
		bracket_count++;
		push(c);
	}
	if (c=='{')
	{
		curly_count++;
		push(c);
	}
	if (c=='[')
	{
		square_count++;
		push(c);
	}
	if (c==')')
	{
		bracket_count--;
		pop();
	}
	if (c=='}')
	{
		curly_count--;
		pop();
	}
	if (c==']')
	{
		square_count--;
		pop();
	}
}

bool isValid(char* s)
{
    bracket_count = 0;
    curly_count = 0;
    square_count = 0;
    if (*s == ']' || *s == ')' || *s == '}')
        return false;
    memset(stack, 0, sizeof stack);
	change_count(*s);
	s++;
	while (*s != '\0')
	{
		if (*s != '{' && *s != '(' && *s != '[' && *s != closed(peek()))
		{
			return false;
		}
		change_count(*s);
		s++;
	}
	return (bracket_count == 0 && square_count == 0 && curly_count == 0);
}

int main()
{
	char* s = "([]{}{((){})})";
	printf("%d\n", isValid(s));
	return 0;
}
