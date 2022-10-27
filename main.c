#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "menu.h"

#define filename "data.csv"

char **data;
int length;

int main(){
    data = loadfile(filename,&length);
    main_menu_page(data,length);
    free(data);
}
