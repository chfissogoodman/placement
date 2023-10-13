//
// Created by chen on 23-10-13.
//

#include "Parser_for_memlist.h"
#include <fstream>
#include <unordered_map>
#include <iostream>

#include "Parser_for_memlist.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool Parser::ParseMemoryData(const std::string &inputFileName, std::vector<MemoryData> &memoryDataList) {

    std::ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        std::cerr << "无法打开输入文件" << std::endl;
        return false;
    }

    std::unordered_map<std::string, MemoryData> memoryDataMap; // 使用unordered_map按memoryType分组
    std::string line;
    MemoryData currentMemoryData;

    while (std::getline(inputFile, line)) {

        if (line.empty()) {
            // 遇到空行，将当前 MemoryData 添加到 memoryDataList 中
            if (!currentMemoryData.memoryType.empty()) {
                if (memoryDataMap.find(currentMemoryData.memoryType) == memoryDataMap.end()) {
                    memoryDataMap[currentMemoryData.memoryType] = currentMemoryData;
                } else {
                    memoryDataMap[currentMemoryData.memoryType].dataPaths.insert(
                            memoryDataMap[currentMemoryData.memoryType].dataPaths.end(),
                            currentMemoryData.dataPaths.begin(),
                            currentMemoryData.dataPaths.end());
                }
                currentMemoryData.memoryType.clear();
                currentMemoryData.dataPaths.clear();
            }
        } else {
            if (currentMemoryData.memoryType.empty()) {
                currentMemoryData.memoryType = line;
            } else {
                currentMemoryData.dataPaths.push_back(line);
            }





//        if (line.empty()) {
//            // 忽略空行
//            continue;
//        }
//
//        if (line.back() == ':') {
//            // 识别到新的内存类型
//            if (!currentMemoryData.memoryType.empty()) {
//                memoryDataList.push_back(currentMemoryData);
//            }
//            currentMemoryData.memoryType = line;
//        } else {
//            // 将路径添加到当前内存类型
//            currentMemoryData.dataPaths.push_back(line);
//        }
        }

//    // 添加最后一个内存类型
//    if (!currentMemoryData.memoryType.empty()) {
//        memoryDataList.push_back(currentMemoryData);
    }

    inputFile.close();
    for (const auto& entry : memoryDataMap) {
        memoryDataList.push_back(entry.second);
    }
    return true;
}




