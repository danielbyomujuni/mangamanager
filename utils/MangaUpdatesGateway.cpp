//
// Created by Daniel Byomujuni on 10/9/23.
//

#include "MangaUpdatesGateway.h"
#include "Memory.h"
#include <curl/curl.h>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;



#define APIURL "https://api.mangaupdates.com/v1/series/"

struct mangaInfo {
    int englishVol;
};

mangaInfo getCurlResult(void *contents, size_t size, size_t nmemb, void *userp) {
}

int MangaUpdatesGateway::getEnglishVolumeCount(std::string MangaId) {
    CURL *curl;

    curl = curl_easy_init();
    if (curl == NULL) {
        return -1;
    }

    std::string url = APIURL + MangaId;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    struct MemoryStruct chunk;
    chunk.memory = static_cast<char *>(malloc(1));
    chunk.size = 0;

    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

    CURLcode result = curl_easy_perform(curl);

    if (result != CURLE_OK) {
        return -1;
    }

    //printf("Size: %lu\n", (unsigned long)chunk.size);

    json ex1 = json::parse(chunk.memory);

    for (json pub : ex1.at("publishers")) {
        if (pub.at("type") == "English") {
            std::string engNotes = pub.at("notes");
            std::string volumesStr = engNotes.substr(0, engNotes.find(" "));

            int volumes = stoi(volumesStr);
            curl_easy_cleanup(curl);
            free(chunk.memory);

            return volumes;
        }
    }

    curl_easy_cleanup(curl);
    free(chunk.memory);
    return 0;
}