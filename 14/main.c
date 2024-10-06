/* 14. Longest Common Prefix
 * Write a function to find the longest common prefix amongst an array of strings
 */
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int shortestStringLength(char** strs, int strsSize) {
	int min=strlen(strs[0]);
	for (int i=1;i<strsSize;i++) {
		if (strlen(strs[i])<min) 
			min=strlen(strs[i]);
	}
	printf("%d\n", min);	
	return min;
}	

char* longestCommonPrefix(char** strs, int strsSize){
	int count=0;
	/* char b[shortestStringLength(strs, strsSize)+1]; */
	char* a = malloc(sizeof(char)*(shortestStringLength(strs,strsSize)+1));
	while (1) {
		char c=strs[0][count];
		if (c=='\0'){
			a[count]='\0';
			return a;
		}
		for (int i=1;i<strsSize;i++) {
			if (strs[i][count] == '\0'){
				a[count]='\0';
				return a;
			}
			if (strs[i][count] != c){
				a[count]='\0';
				printf("Found non-matching character %c\n", strs[i][count]);
				printf("%s\n", a);
				return a;		
			}
		}
		a[count]=c;
		count++;
	}
}


int main(){
	char* strs[] = {"flower", "flow", "flight"};
	char* c = longestCommonPrefix(strs, 3);
	printf("%s\n", c);
	return 0;
}
