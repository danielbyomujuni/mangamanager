//
// Created by Daniel Byomujuni on 10/9/23.
//

#ifndef MANGAUPDATES_MEMORY_H
#define MANGAUPDATES_MEMORY_H


struct MemoryStruct {
    char *memory;
    size_t size;
};

size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp);


#endif //MANGAUPDATES_MEMORY_H
