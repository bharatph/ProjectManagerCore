#include <iostream>

#include <ProjectManagerCore.hpp>

using namespace pm;

int main(int argc, char *argv[]){
  ProjectManagerCore pmc;
  Project &p = *(new Project());
  pmc.addProject(p);
  return 0;
}
