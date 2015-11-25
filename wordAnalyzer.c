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
#define width 100
#define height 10000


int countWords(FILE *f,int* now,char ch[height][width],int instances[height]){
   int x;

   *now=0;
   int count = 0;
       while (fscanf(f, "%[^" WORD "]",ch[count]) != EOF
        && fscanf(f, "%10[" WORD "]", ch[count]) != EOF) {
        printf("%d\n",count );


        for(x=0;x<count;x++) {

          if(instances[x]==0) {
            instances[x]=1;
          }


          if((strcasecmp(ch[count],ch[x]))==0) { /* Compare if the two words match, 
          case insensitive*/
        
            if(fscanf(f, "%[^" WORD "]",ch[count]) != EOF
            && fscanf(f, "%10[" WORD "]",ch[count]) != EOF) /* Since the words match,
            now we have to overwrite the double word by scanning the next set of characters.*/
		
		if((strcasecmp(ch[count-1],ch[x]))==0) {
			count--;

		}

              instances[x]++;
            
              (*now)++;
          }
        }
      
 puts(ch[count]);
        count++;
        (*now)++;
    }



   return count;
}

int main(void){

   int uniquewordCount=0,wordCount=0,i;
   char ch[height][width];
   int instances[height];
   FILE *rFile = fopen("test3.txt", "r");
   uniquewordCount += countWords(rFile,&wordCount,ch,instances);



   for(i=0;i<uniquewordCount;i++){
      printf("x %d ",instances[i] );
    puts(ch[i]);
   

   }
   printf("Amount of unique words: %d\n", uniquewordCount);
   printf("Amount of words: %d\n", wordCount);
   return 0;
}

