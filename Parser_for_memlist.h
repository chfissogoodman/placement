//
// Created by chen on 23-10-13.
//

#ifndef MEMORYLIST_C_F_PARSER_FOR_MEMLIST_H
#define MEMORYLIST_C_F_PARSER_FOR_MEMLIST_H

#include <vector>
#include <string>
#include "Database.h"

class Parser {
public:
    static bool ParseMemoryData(const std::string& inputFileName, std::vector<MemoryData>& memoryDataList);
};

#endif //MEMORYLIST_C_F_PARSER_FOR_MEMLIST_H
