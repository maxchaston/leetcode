#include <stdbool.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
bool compare_two_words(char *word1, char *word2, char *order)
{
    int word1_len = strlen(word1);
    int word2_len = strlen(word2);
	int shorterlen = word1_len>word2_len ? word2_len : word1_len;
	for (int i=0; i<shorterlen; i++)
    {
        char *e1 = strchr(order, word1[i]);
        char *e2 = strchr(order, word2[i]);
        int index1 = (int)(e1-order);
        int index2 = (int)(e2-order);
		printf("%c index: %d\n%c index:%d\n", word1[i], index1, word2[i], index2);
        if (index1<index2 || (index1==index2 && i==shorterlen-1 && word1_len <= word2_len))
            return true;
		if (index1>index2)
			return false;
    }
    return false;
}


bool isAlienSorted(char ** words, int wordsSize, char * order){
    for (int i=0; i<wordsSize-1; i++)
    {
        if (!compare_two_words(words[i],words[i+1],order))
            return false;
    }
    return true;
}
