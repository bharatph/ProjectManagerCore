#include <ProjectManagerCore.hpp>

#include <map>

#include <Project.hpp>
#include <Operation.hpp>
#include <unistd.h>
#include <thread>

using namespace pm;

pm::ProjectManagerCore::ProjectManagerCore(){

}

pm::Operation pm::ProjectManagerCore::getProjects(Query query){
  //TODO get the project based on the query
  return Operation([&](Operation &op){
    if(projects.size() == 0){
      op.fireEvent(PMEvent::NOT_FOUND, projects);
      return;
    }
    //search the map fields,
    //if empty fire not found and return
    //else return the results
    op.fireEvent(PMEvent::FATAL_ERROR, projects);
    op.fireEvent(PMEvent::SUCCESS, projects);
  });
}


pm::Operation pm::ProjectManagerCore::addProject(pm::Project project){
  return Operation([&](Operation &op){
    projects[project.getUid()] = new Project(project);
    op.fireEvent(PMEvent::SUCCESS, projects);
    //assuming there is no error with map
    //error is checked only for persistence storage
  });
}

pm::Operation pm::ProjectManagerCore::modifyProject(pm::Project &project){
  return Operation([&](Operation &op){
    projects[project.getUid()] = &project;
    op.fireEvent(PMEvent::SUCCESS, projects);
    //error is checked only for persistence storage
  });
}

pm::Operation pm::ProjectManagerCore::removeProject(pm::Project &project){
  return Operation([&](Operation &op){
    projects.erase(project.getUid());
    op.fireEvent(PMEvent::SUCCESS, projects);
  });
}
