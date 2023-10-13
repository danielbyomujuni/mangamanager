//
// Created by Daniel Byomujuni on 10/9/23.
//

#ifndef MANGAMANAGER_CSVGATEWAY_H
#define MANGAMANAGER_CSVGATEWAY_H

#include <string>
#include <vector>

struct Manga {
    std::string title;
    std::string id;
    int volumes;
};

class CSVGateway {
    std::string workingFolder;
public:
    CSVGateway(std::string folder);
    CSVGateway();
    void setRecord(std::string MangaName, std::string MangaID, int32_t VolumesOwned);
    bool doesRecordExist(std::string MangaName);
    void appendRecord(std::string MangaName, std::string MangaID, int32_t VolumesOwned);
    void updateRecord(std::string MangaName, std::string MangaID, int32_t VolumesOwned);
    Manga getRecord(std::string MangaName);
    std::vector<Manga> allRecords();
};


#endif //MANGAMANAGER_CSVGATEWAY_H
