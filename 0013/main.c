#include <stdio.h>

int romanToInt(char* s)
{
	int sum = 0;
	char* c;
	char prev_c;
	for (c = s; *c != '\0'; c++)
	{
		printf("%c\n", *c);
		switch (*c)
		{
		case 'I':
			sum+=1;
			break;
		case 'V':
			if (prev_c == 'I')
				sum+=3;
			else
				sum+=5;
			break;
		case 'X':
			if (prev_c == 'I')
				sum+=8;
			else
			  sum+=10;
			break;
		case 'L':
			if (prev_c == 'X')
				sum+=30;
			else
			  sum+=50;
			break;
		case 'C':
			if (prev_c == 'X')
				sum+=80;
			else
			  sum+=100;
			break;
		case 'D':
			if (prev_c == 'C')
				sum+=300;
			else
			  sum+=500;
			break;
		case 'M':
			if (prev_c == 'C')
				sum+=800;
			else
			  sum+=1000;
			break;
		}
		prev_c = *c;
	}
	return sum;
}

int main()
{
	char* s = "IVXLCDM";
	int value = romanToInt(s);
	printf("Val: %d\n", value);
	return 0;
}
