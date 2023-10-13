//
// Created by chen on 23-10-13.
//

#ifndef MEMORYLIST_C_F_DATABASE_H
#define MEMORYLIST_C_F_DATABASE_H
#pragma once

#include "Parser_for_memlist.h"
#include <vector>

struct MemoryData{
    std::string memoryType;//内存类型
    std::vector<std::string>dataPaths;//内存的绝对路径
};


class Database {
public:
    void AddMemoryData(const MemoryData& memoryData){
        memoryDataList_.push_back(memoryData);
    }
//    auto GetMemoryDataList(std::vector<MemoryData>&memoryDataList){
//    return memoryDataList_;
//}

private:
    std::vector<MemoryData> memoryDataList_;

};

#endif //MEMORYLIST_C_F_DATABASE_H
