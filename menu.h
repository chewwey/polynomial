#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Poly.h"

void plus_poly(char **data,int length){
    int id1,id2,size;
    int poly1_max,poly2_max;
    int *poly1;
    int *poly2;
    int *sum;
    printAll(data,length);
    printf("Enter id of the first Polynomial\n");
    scanf("%d" , &id1);
    printf("Enter id of the second Polynomial\n");
    scanf("%d" , &id2);
    poly1 = convert_int(data[id1],&poly1_max);
    poly2 = convert_int(data[id2],&poly2_max);
    sum = add(poly1,poly2,poly1_max,poly2_max);
    size = max(poly1_max,poly2_max);
    printf("The sum is: ");
    printPoly(sum,size);
    printf("\n");
    free(poly1);
    free(poly2);
    free(sum);
}

void minus_poly(char **data,int length){
    int id1,id2,size;
    int poly1_max,poly2_max;
    int *poly1;
    int *poly2;
    int *minu;
    printAll(data,length);
    printf("Enter id of the first Polynomial\n");
    scanf("%d" , &id1);
    printf("Enter id of the second Polynomial\n");
    scanf("%d" , &id2);
    poly1 = convert_int(data[id1],&poly1_max);
    poly2 = convert_int(data[id2],&poly2_max);
    minu = minus(poly1,poly2,poly1_max,poly2_max);
    size = max(poly1_max,poly2_max);
    printf("The minus is: ");
    printPoly(minu,size);
    printf("\n");
    free(poly1);
    free(poly2);
    free(minu);
}

void evaluate_poly(char **data,int length){
    int id, x,poly_max;
    printAll(data,length);
    printf("Enter id of the Polynomial you want to calculate\n");
    scanf("%d" , &id);
    printf("What should x equal: \n");
    scanf("%d", &x);
    int *poly = convert_int(data[id],&poly_max);
    int done = subtitude(poly,x,poly_max);
    printf("Your evaluated polynomial is: %d\n" ,done);
    free(poly);
}

void multi_poly(char **data,int length){
    int id1,id2,poly1_max,poly2_max;
    int *poly1;
    int *poly2;
    printAll(data,length);
    printf("Enter id of the first Polynomial\n");
    scanf("%d" , &id1);
    printf("Enter id of the second Polynomial\n");
    scanf("%d" , &id2);
    poly1 = convert_int(data[id1],&poly1_max);
    poly2 = convert_int(data[id2],&poly2_max);
    int *mul = mul_poly(poly1,poly2,poly1_max,poly2_max);
    int size = poly1_max + poly2_max -1;
    printf("The multiply of two polynomial is: ");
    printPoly(mul,size);
    printf("\n");
    free(poly1);
    free(poly2);
    free(mul);
}

void compute_menu(char **data,int length){
    int choice;
    printf("What do you want to compute\n");
    printf("1) Plus polynomial\n");
    printf("2) Minus polynomial\n");
    printf("3) evaluate polynomial\n");
    printf("4) Mulitiply polynomial\n");
    printf("5) back to main menu");
    printf("\nChoice--> ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            plus_poly(data,length);
            break;
        case 2:
            minus_poly(data,length);
            break;
        case 3:
            evaluate_poly(data,length);
            break;
        case 4:
            multi_poly(data,length);
            break;
        case 5:
            break;
        }
}

void main_menu_page(char **data,int length) {
    while(1){
        int choice;
        printf("What do you want to do\n");
        printf("1) look at polynomial\n");
        printf("2) compute polynomial\n");
        printf("3) Exit\n");
        printf("\nChoice--> ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printAll(data,length);
            break;
        case 2:
            compute_menu(data,length);
            break;
        case 3:
            printf("goodbye\n");
            return;
        }
    }
}
