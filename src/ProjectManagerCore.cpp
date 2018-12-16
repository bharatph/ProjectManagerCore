#include <ProjectManagerCore.hpp>

#include <map>

#include <Project.hpp>
#include <Operation.hpp>

using namespace pm;

pm::ProjectManagerCore::ProjectManagerCore(){

}

pm::Operation &pm::ProjectManagerCore::getProjects(Query query){
  //TODO get the project based on the query
  return *new Operation([](){

  });
}

pm::Operation &pm::ProjectManagerCore::addProject(pm::Project project){
  projects[project.getUid()] = new Project(project);
  return *new Operation([](){
    //add project and direct callabcks
  });
}

pm::Operation &pm::ProjectManagerCore::modifyProject(pm::Project &project){
  return *new Operation([](){

  });
}

pm::Operation &pm::ProjectManagerCore::removeProject(pm::Project &project){
  return *new Operation([](){

  });
}
