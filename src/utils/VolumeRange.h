//
// Created by Daniel Byomujuni on 1/8/24.
//

#include <cstring>
#include <cstdlib>
#include <cstdio>

#ifndef MANGAMANAGER_VOLUMERANGE_H
#define MANGAMANAGER_VOLUMERANGE_H

int max(int current, int i);

#endif //MANGAMANAGER_VOLUMERANGE_H


int *volumeRangeToArray(int *arrlen, char* volRange) {
    *arrlen = 0;
    int *arr = {};

    char* currentNumber = new char[256];
    memset( currentNumber, '\0', 256*sizeof(char) );

    int rangestart = -1;
    int i = -1;
    do {
        i++;
        if (volRange[i] == ',' || volRange[i] == '\0') {
            int current = atoi(currentNumber);

            int newSize = max(current,*arrlen);

            int *temp = new int[newSize];
            memset( temp, 0, newSize*sizeof(int) );

            for (int old = 0; old < *arrlen; old++) {
                temp[old] = arr[old];
            }
            if (rangestart != -1) {
                for (int numrange = rangestart; numrange < current; numrange++) {
                    temp[numrange] = 1;
                }
                rangestart = -1;
            }

            temp[current] = 1;

            free(arr);
            arr = temp;
            *arrlen = max(current + 1,*arrlen);
            free(currentNumber);

            char* currentNumber = new char[256];
            memset( currentNumber, '\0', 256*sizeof(char) );

            continue;
        }
        if (volRange[i] == '-') {
            rangestart = atoi(currentNumber);
            free(currentNumber);
            currentNumber = new char[256];
            continue;
        }

        char digit[1];
        digit[0] = volRange[i];
        strcat(currentNumber, digit);

    } while (volRange[i] != '\0');

    return arr;
}

int max(int a, int b) {
    if (a >= b) {
        return a;
    }
    return b;
}
