#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main() {
    FILE *fptr;

    fptr = fopen("input.txt", "r");
    int symb = 0;
    int floor = 0;
    int index = 1;

    if(fptr == NULL) {
        std::cout << "Bad";
        exit(1);
    }

    while(1) {
        symb = fgetc(fptr);
        
        if(feof(fptr)) {
            break;
        }

        if(symb == 40) {
            floor += 1;
        } else {
            floor -= 1;
        }

        if(floor == -1) {
            std::cout << index << "\n";
        }

        index++;
    }

    std::cout << floor;

    fclose(fptr);
    return 0;
}