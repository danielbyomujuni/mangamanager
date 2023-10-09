//
// Created by Daniel Byomujuni on 10/9/23.
//

#include "CSVGateway.h"
#include <fstream>

void CSVGateway::setRecord(std::string MangaName, std::string MangaID) {
        // file pointer
        std::fstream fstream;

        // opens an existing csv file or creates a new file.
        std::string home_dir = getenv("HOME");

        fstream.open(home_dir + "/Documents/mangaUpdates.csv", std::fstream::out | std::fstream::app);
        fstream << MangaName << ", " << MangaID << ", " << 0 << std::endl;

        fstream.close();
    }