//
// Created by Daniel Byomujuni on 10/9/23.
//

#ifndef MANGAMANAGER_CSVGATEWAY_H
#define MANGAMANAGER_CSVGATEWAY_H

#include <string>

class CSVGateway {
public:
    void setRecord(std::string MangaName, std::string MangaID, int32_t VolumesOwned);
    bool doesRecordExist(std::string MangaName);
    void appendRecord(std::string MangaName, std::string MangaID, int32_t VolumesOwned);
    void updateRecord(std::string MangaName, std::string MangaID, int32_t VolumesOwned);
};


#endif //MANGAMANAGER_CSVGATEWAY_H
