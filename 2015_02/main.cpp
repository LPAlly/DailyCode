#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main() {
    FILE *fptr;

    char buffer[12];
    char *line = (char *) malloc(sizeof(buffer));

    if(line == NULL) {
        std::cout << "Bad malloc \n";
        exit(1);
    }

    line[0] = '\0';

    fptr = fopen("input.txt", "r");
    int symb = 0;

    if(fptr == NULL) {
        std::cout << "Bad ptr \n";
        exit(1);
    }

    while(!feof(fptr)) {
        symb = fgetc(fptr);
    }


    fclose(fptr);
    return 0;
}