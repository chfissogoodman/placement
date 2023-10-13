#include "Parser_for_memlist.h"
#include "Database.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<MemoryData> memoryDataList;
    Database database;

    if (Parser::ParseMemoryData("tc01_memorylist_c.f", memoryDataList)) {
        for (const MemoryData& memoryData : memoryDataList) {
            database.AddMemoryData(memoryData);
        }
    } else {
        std::cerr << "解析数据失败。" << std::endl;
    }



    return 0;
}

