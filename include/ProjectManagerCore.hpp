#ifndef _PROJECT_MAN_CORE_H
#define _PROJECT_MAN_CORE_H

#include <map>
#include <Project.hpp>
#include <Query.hpp>
#include <Operation.hpp>

namespace pm {
  class ProjectManagerCore {
  private:
    std::map<std::string, Project *> projects;
  public:
    //initializes the ProjectManagerCore, reads local files and adds to memory
    ProjectManagerCore();
    //Returns an active object, WARNING: do not delete the returned object
    Operation getProjects(Query);
    Operation addProject(Project);
    Operation modifyProject(Project &);
    Operation removeProject(Project &);
  };
}

#endif
