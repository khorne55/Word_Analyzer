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


int countWords(FILE *f){
   int count = 0;
   char ch;
   while ((ch = fgetc(f)) != EOF){
       if ((ch == ' ') || (ch=='\n'))
           count++;
   }
   return count;
}

int main(void){

   int wordCount = 0;
   FILE *rFile = fopen("test.txt", "r");
   wordCount += countWords(rFile);
   printf("%d\n", wordCount);
   return 0;
}
