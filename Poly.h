#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

size_t lineLim = 64;

char **loadfile(char *fn,int *len){
    FILE *fp = fopen(fn,"r");
    if (!fp){
        printf("can't open file");
    }
    char **line = (char **)malloc(lineLim * sizeof(char *));

    char buffer[1000];
    int i = 0;
    while (fgets(buffer,lineLim,fp))
    {
        //check line array if full increase if over limited increase it 
        if (i == lineLim){
            lineLim *= 2;
            char **line = realloc(line, lineLim * sizeof(char*));
            if (!line){
                printf("can't allocate ");
            }
        }
        buffer[strlen(buffer)] = '\0';
        int slen = strlen(buffer);
        char *poly = (char *)malloc((slen + 1) * sizeof(char));
        strcpy(poly,buffer);
        line[i] = poly;
        i++;
    }
    *len = i; // return length of line
    return line;
    free(buffer);
    fclose(fp);
}

int* convert_int(char *arr,int *m){
    int len=strlen(arr),i;
    char *temp = (char*)malloc(len * sizeof(char));
    memcpy(temp,arr,sizeof(char) * len);

    const char *tok;
    int column = 0;

	int *a = (int*)malloc(256*sizeof(int));
    char* value = strtok(temp, ", ");
    while (value) {
                int sepInt = atoi(value);
                a[column] = sepInt;
                value = strtok(NULL, ", ");
                column++;
            }
    a = realloc(a,column*sizeof(int));
    *m = column;
    free(temp);
    return a;
}

void printPoly(int* poly, int n)
{
    for (int i=0; i< n; i++){
        printf("%d",poly[i]);
        if (i != 0)
        printf("x^%d",i);
        if (i != n-1)
        printf(" + ");
    }
}   

void printAll(char **data,int length){
    int poly_max;
    for(int i = 0;i < length;i++){
        int *poly = convert_int(data[i],&poly_max);
        printf("%d: ",i);
        printPoly(poly,poly_max);
        printf("\n");
    }
}

// find max length 
int max(int m, int n) {  
    return (m > n)? m: n; 
}

int *add(int *A, int *B, int m, int n)
{
   int size = max(m, n);
   int *sum = (int*)malloc(size*sizeof(int));
   memset(sum, 0, size*sizeof(int));
   
   for (int i = 0; i<m; i++)
     sum[i] = A[i];
 
   for (int i=0; i<n; i++)
       sum[i] += B[i];
    
   return sum;
}

int *minus(int *A, int *B, int m, int n)
{
   int size = max(m, n);
   int *minus = (int*)malloc(size*sizeof(int));
   memset(minus, 0, size*sizeof(int));
   
    for (int i = 0; i<m; i++)
        minus[i] = A[i];
 
   for (int i=0; i<n; i++)
        minus[i] -= B[i];
    
   return minus;
}

int subtitude(int *A,int x,int m){
    int subbed = 0;
    for (int i = 0; i < m; i++) {
        subbed += A[i] * pow(x, i);
    }
    return subbed;
}

int *mul_poly(int *A, int *B, int m, int n)
{
    int size = m + n - 1;
    int *prod = (int*)malloc(size*sizeof(int));
    memset(prod, 0, size*sizeof(int));
    
   for (int i=0; i<m; i++)
   {
     for (int j=0; j<n; j++)
         prod[i+j] += A[i]*B[j];
   }
 
   return prod;
}
