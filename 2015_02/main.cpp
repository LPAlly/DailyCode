#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

int get_line(FILE *fptr, char *buffer, size_t bufferLen) {
    char *end = buffer + bufferLen - 1;
    char *index = buffer;
    int character;

    while((character = getc(fptr)) != EOF && character != '\n' && index < end) {
        *index++ = character;
    }

    *index = '\0';
    
    return character == EOF ? EOF : index - buffer;
}

int calculate_square_foot(char *buffer, size_t bufferLen) {
    int l, w, h;
    int sepPos[2];
    int nbSepFound = 0;

    for(int index = 0; index < bufferLen; index++) {
        if(buffer[index] == 'x') {
            buffer[index] = '\0';

            sepPos[nbSepFound] = index;
            nbSepFound++;
        }
    }

    l = atoi(buffer);
    w = atoi(buffer+sepPos[0] + 1);
    h = atoi(buffer+sepPos[1] + 1);

    int minSide = std::min({l*w, w*h, h*l});

    return 2*l*w + 2*w*h + 2*h*l + minSide;
}

int main() {
    FILE *fptr;

    char buffer[12];
    int index = 1;
    int nbElements = 0;
    unsigned long squareFoot = 0;

    fptr = fopen("input.txt", "r");

    if(fptr == NULL) {
        std::cout << "Bad ptr \n";
        exit(1);
    }

    nbElements = get_line(fptr, buffer, sizeof(buffer));

    while(nbElements != EOF) {
        squareFoot += calculate_square_foot(buffer, nbElements);
        nbElements = get_line(fptr, buffer, sizeof(buffer));
        index++;
    }

    std::cout << squareFoot << std::endl;

    fclose(fptr);
    return 0;
}