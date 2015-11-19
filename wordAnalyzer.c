/*
wordAnalyzer.c

Created by Piotr Kurzynoga
Date 17/11/2015

The aim of this module is to perform various operations on a text file.
 >Counting amount of words.
 >Listing unique words and how many there are not case sensitive.
 >Number of occurences of specific words.
 >Shows a summary of the number of words,leters,digits,whitespaces and symbols.

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define WORD "A-Za-z"

int countWords(FILE *f){
   char ch[100][100];
   int cmp,x;
   int count = 0;
       while (fscanf(f, "%[^" WORD "]",ch[count]) != EOF
        && fscanf(f, "%10[" WORD "]",ch[count]) != EOF) {

        if(count>0) {
              printf("%d\n",count );

        for(x=0;x<count;x++) {

          if((strcasecmp(ch[count],ch[x]))==0)

              printf("String is equal\n");
        }
      }
        puts(ch[count]);
        count++;
    }
    puts(ch[13]);

   return count;
}

int main(void){

   int wordCount = 0;
   FILE *rFile = fopen("test2.txt", "r");
   wordCount += countWords(rFile);
   printf("%d\n", wordCount);
   return 0;
}

