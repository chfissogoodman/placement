//
// Created by 86183 on 2023/9/6.
//
#include "exporter.h"
#include "place.h"
#include <fstream>

Exporter::Exporter(const Database &db):database(db) {}

void Exporter::exportLayout(const std::string &filename) const {
  ofstream file(filename);
  if(!file.is_open()){
    cerr<<"文件打开失败"<<filename<<endl;
    return;
  }
  const vector<Instance>&instance=database.getInstance();

  file<<"实现最短总线长的单元布局为："<<endl;
  for(const Instance&Inst:instance)
  {
    file<<Inst.name<<" "<<Inst.row<<" "<<Inst.col<<endl;
  }
  file<<endl;
}
