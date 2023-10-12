//
// Created by 86183 on 2023/9/6.
//

#ifndef PLACEMENT_INCLUDE_DATABASE_H_
#define PLACEMENT_INCLUDE_DATABASE_H_

#endif //PLACEMENT_INCLUDE_DATABASE_H_
#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Instance {
  string name;
  int row;
  int col;
  Instance(const string &name):name(name){};
  Instance(const string &name, int row, int col) : name(name), row(-1), col(-1) {};
};

struct Pin {
  string instance_name;//引脚所属的实例名称
};

struct Net {
  string name;
  vector<Pin> pins;
  vector<Instance>connected_pin_to_Instances;
  Net(const string&name):name(name){};
  //用来读数据的
  void addConnectedInstance(const string &instName){
    connected_pin_to_Instances.push_back(instName);
  }

};

class Database {
 public:
  Database(int rows, int cols) : dieRows(rows), dieCols(cols) {};

  void addInstance(const Instance &Inst) {
    instances.push_back(Inst);
  }
  void addNet(Net &net) {
    nets.push_back(net);
  }
  const vector<Instance> &getInstance() const {
    return instances;
  }
  const vector<Net> &getNet() const {
    return nets;
  }
  int getDieRows() const
  {
    return dieRows;
  }

  int getDieCols() const
  {
    return dieCols;
  }
 private:
  vector<Instance> instances;
  vector<Net> nets;
  int dieRows, dieCols;
};