//
// Created by Daniel Byomujuni on 1/8/24.
//
#include <cstring>
#include <cstdlib>
#include <cstdio>

int max(int current, int i);

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
            memset( currentNumber, '\0', 256*sizeof(char) );
            continue;
        }

        char digit[2];
        memset( digit, '\0', 2*sizeof(char));

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


char *volumeArrayToRange(int arrlen, int *volumesArray) {
    char* range = new char[256];
    memset( range, '\0', 256*sizeof(char));
    int strlen = 0;

    for (int i = 0; i < arrlen; i++) {
        if (volumesArray[i] == 1) {
            char *digit = new char[2];
            memset( digit, '\0', 2*sizeof(char));

            digit[0] = i + '0';

            strcat(range, digit);
            strlen++;

            if (volumesArray[i+1] != 1) {
                continue;
            }

            char *rangeEnd = new char[3];
            memset( rangeEnd, '\0', 3*sizeof(char));

            rangeEnd[0] = '-';
            while (i+1 < arrlen && volumesArray[i+1] == 1) { i++;}
            rangeEnd[1] = i + '0';
            strcat(range, rangeEnd);
            strlen += 2;

        } else {
            if (strlen == 0) {
                continue;
            }
            if (range[strlen-1] == ',' || range[strlen-1] == '-') {
                continue;
            }
            strcat(range, ",");
            strlen++;
        }
    }

    if (range[strlen-1] == ',') {
        range[strlen-1] = '\0';
    }

    return range;
}