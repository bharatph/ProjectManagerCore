#include <iostream>
#include <map>
#include <Project.hpp>

#include <ProjectManagerCore.hpp>

using namespace pm;
using namespace std;

int main(int argc, char *argv[]){
  ProjectManagerCore pmc;
  Project &p = *(new Project());
  p.name = "Hades";
  pmc.addProject(p).on(PMEvent::SUCCESS, [](map<string, Project *> prjs){
    std::cout << "Added " << std::endl;
  });

  pmc.getProjects(Query()).on(PMEvent::FATAL_ERROR, [](map<string, Project *> prjs){
     std::cout << "Fatal error" << std::endl;
  }).on(PMEvent::NOT_FOUND, [](map<string, Project *> prjs){
    std::cout << "Not found" << std::endl;
  }).on(PMEvent::SUCCESS, [](map<string, Project *> prjs){
    std::cout << "Success: The project is found" << std::endl;
  });

  pmc.modifyProject(p).on(PMEvent::SUCCESS, [](map<string, Project *> prjs){
    std::cout << "modified" << std::endl;
  });
  pmc.removeProject(p).on(PMEvent::SUCCESS, [](map<string, Project *> prjs){
    std::cout << "removed" << std::endl;
  });

  pmc.getProjects(Query()).on(PMEvent::NOT_FOUND, [](map<string, Project *> prjs){
    std::cout << "Not found" << std::endl;
  });


while(1){
  //
}
  return 0;
}
