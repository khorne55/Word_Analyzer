	#include <stdio.h>

	int main(void) /* C89 ANSI */
	{
	    FILE *fp;
	    int r,n;
	    const char *filename = "test.txt";
	     
	    if ((fp = fopen(filename, "r")) == NULL) {
	        fprintf(stderr, "error: file" "\n");
	        return 1;
	    }  
	     
	    n = 0;
	    while ((r = fscanf(fp, "%*10s")) != EOF)
	        n++;
	     
	    if (ferror(fp) != 0) {
	        fprintf(stderr, "error: read file" "\n");
	        fclose(fp);
	        return 1;
	    }  
	     
	    if (n == 1)
	        printf("there is %d word" "\n", n);
	    else
	        printf("there are %d words" "\n", n);
	     
	    return 0;
}