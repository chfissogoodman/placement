//
// Created by 86183 on 2023/9/6.
//

#ifndef PLACEMENT__EXPORTER_H_
#define PLACEMENT__EXPORTER_H_

#endif //PLACEMENT__EXPORTER_H_
#pragma once

#include "database.h"

class Exporter
{
 public:
  Exporter(const Database &db);
  void exportLayout(const string &filename)const;
 private:
  const Database &database;
};