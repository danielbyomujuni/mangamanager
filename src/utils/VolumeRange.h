//
// Created by Daniel Byomujuni on 1/8/24.
//

#ifndef MANGAMANAGER_VOLUMERANGE_H
#define MANGAMANAGER_VOLUMERANGE_H

int max(int current, int i);

#endif //MANGAMANAGER_VOLUMERANGE_H


int *volumeRangeToArray(int *arrlen, char* volRange);
char *volumeArrayToRange(int arrlen, int *volumesArray);

void addVolumeArrays(int **volumesArray, int *arrLen, int *opperandArray, int opperandLen);