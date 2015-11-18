#include <stdio.h>

int main()
{
   FILE *fp;
   char str[200][100];
   int i,count=0;
   char st[100];



   /* opening file for reading */
   fp = fopen("test2.txt" , "r");
   if(fp == NULL) 
   {
      perror("Error opening file");
      return(-1);
   }

   while(( fgets (str[i], 200, fp)!=NULL) && (i<200)) 
   {
      /* writing content to stdout */

      puts(str[i++]);
   }
   fclose(fp);

   while(fscanf(fp,"%[^A-Zz-a]",st) != EOF
        && fscanf(fp, "%9[A-Zz-a]",st) != EOF) { 
   puts(st);
   count++;
}
   printf("%d",count);
   return(0);
}