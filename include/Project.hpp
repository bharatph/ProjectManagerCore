#ifndef _PROJECT_MODEL_H
#define _PROJECT_MODEL_H

#include <iostream>
#include <crossguid/guid.hpp>

namespace pm {
  class Project {
  private:
    std::string uid;
  public:
    std::string name;
    std::string description;
    std::string repositoryType;
    std::string repositoryLink;

    std::string getUid(){
      return uid;
    }


    Project(){
      uid = xg::newGuid().str();
    }
    Project(const Project& p){
      uid = p.uid;
      name = p.name;
      description = p.description;
      repositoryType = p.repositoryType;
      repositoryLink = p.repositoryLink;
    }
  };
}

#endif
