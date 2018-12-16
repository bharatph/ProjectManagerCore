cmake_minimum_required(VERSION 3.0)

project(ProjectManagerCore)

find_package(clog)
find_package(crossguid REQUIRED)
find_package(EventManager)


file(GLOB_RECURSE PM_HDRS "include/*.hpp")
file(GLOB_RECURSE PM_SRCS "src/*.cpp")

add_library(ProjectManagerCore ${PM_SRCS} ${PM_HDRS})

target_compile_features(ProjectManagerCore PRIVATE cxx_enum_forward_declarations)

project(pm_test)

add_executable(pm_test project_manager_test.cpp)
target_compile_features(pm_test PRIVATE cxx_enum_forward_declarations)


target_include_directories(ProjectManagerCore PUBLIC include)
target_include_directories(ProjectManagerCore PRIVATE ${CLOG_INCLUDE_DIR})
target_include_directories(ProjectManagerCore PRIVATE ${DOT_INCLUDE_DIR})

target_link_libraries(ProjectManagerCore crossguid)
target_link_libraries(ProjectManagerCore ${CLOG_LIBS})
target_link_libraries(ProjectManagerCore ${DOT_LIBS})

target_link_libraries(pm_test ProjectManagerCore)
