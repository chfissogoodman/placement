//
// Created by 86183 on 2023/9/6.
//

#ifndef PLACEMENT_INCLUDE_PARSER_H_
#define PLACEMENT_INCLUDE_PARSER_H_

#endif //PLACEMENT_INCLUDE_PARSER_H_

#pragma once
#include <string>
#include "database.h"

class Parser{
 public:
  Parser();
  bool parseFile(const string &filename);
  const Database&getDatabase()const;
 private:
  Database database_;
};