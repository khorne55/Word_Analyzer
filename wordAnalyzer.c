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

void hello(int*a,int* b) {
*a=2;
*b=3;
(*a)++;
a++;
}

int countWords(FILE *f,int* now){
   char ch[100][100];
   int x;
   *now=0;
   int count = 0;
       while (fscanf(f, "%[^" WORD "]",ch[count]) != EOF
        && fscanf(f, "%10[" WORD "]",ch[count]) != EOF) {

        if(count>0) {

        for(x=0;x<count;x++) {

          if((strcasecmp(ch[count],ch[x]))==0) {
            if(fscanf(f, "%[^" WORD "]",ch[count]) != EOF
            && fscanf(f, "%10[" WORD "]",ch[count]) != EOF) 
              printf("String is equal\n");
              (*now)++;
          }
        }
      }
        puts(ch[count]);
        count++;
        (*now)++;
    }
    puts(ch[13]);
    printf("%d\n",*now );

   return count;
}

int main(void){

   int uniquewordCount=0,wordCount=0;
   FILE *rFile = fopen("test2.txt", "r");
   uniquewordCount += countWords(rFile,&wordCount);
   int a,b;
   hello(&a,&b);
   printf("%d\n",(a+b));
   printf("Amount of unique words: %d\n", uniquewordCount);
   printf("Amount of words: %d\n", wordCount);
   return 0;
}

