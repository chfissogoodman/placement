//
// Created by 86183 on 2023/9/6.
//
#include "parser.h"
#include <fstream>
#include <sstream>

bool Parser::parseFile(const std::string &filename) {
  ifstream file(filename);
  if(!file.is_open())
  {
    cout<<"无法打开文件"<<filename<<endl;
    return false;
  }
  string line;
  // 从file中读取文本储存到line中
  while(getline(file,line)){
    if(line.empty()||line[0]=='#')
    {
      continue;
    }
// 将字符串按空格分割成多个部分然后逐个读取
    istringstream iss(line);
    string keyword;
    iss>>keyword;

    if(keyword=="DieSize")
    {
      int rows,cols;//读入可布局的行列数
      iss>>rows>>cols;
      database_=Database(rows,cols);
    }
    else  if(keyword=="NumInstances")
    {
      int numInstances;
      iss>>numInstances;
      for(int i=0;i<numInstances;++i){
        getline(file,line);
        istringstream inst_ss(line);// 将字符串按空格分割成多个部分然后逐个读取
        string instName;
        inst_ss>>keyword;
        inst_ss>>instName;
        database_.addInstance(Instance(instName));
      }
    } else if(keyword=="NumNets")
    {
      int numNets;
      iss>>numNets;
      for(int i=0;i<numNets;++i){
        getline(file,line);
        istringstream iss_(line);
        string netName;
        string keyword_;
        int numPins;
        iss_>>netName>>keyword_>>numPins;
        Net net(keyword_);

        for (int j = 0; j <numPins ; ++j) {
          getline(file,line);
          istringstream iss_1(line);
          string pin_to_Inst;
          iss>>keyword;
          iss_1>>pin_to_Inst;
          net.addConnectedInstance(pin_to_Inst);
        }
        database_.addNet(net);
      }
    }
  }
  file.close();
  return true;

}
const Database&Parser::getDatabase() const {
  return database_;
}