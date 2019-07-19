cmake_minimum_required(VERSION 3.1)

project(algorithms.unittest)

set(GMOCK_DIR "$ENV{GMOCK_DIR}")
set(GTEST_DIR "$ENV{GTEST_DIR}")

MESSAGE( STATUS "Target artifacts will be installed in: " ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} )
MESSAGE( STATUS "Using GTest from: " ${GTEST_DIR} )
MESSAGE( STATUS "Using GMock from: " ${GMOCK_DIR} )

set(IMPLEMENTATION_SOURCES
  # List all implementation files to be built in this project
<<<<<<< HEAD
  BinaryTreeTest.cpp
=======
>>>>>>> 6e0c9ae3c26036a45db2722d4ca92daeee83b799
  sortTest.cpp
  testmain.cpp)

include_directories(
  "${GMOCK_DIR}/include"
  "${GTEST_DIR}/include"
  "../interface")

link_directories(
  "${GMOCK_DIR}/build"
  "${GMOCK_DIR}/build/gtest"
  ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})

add_executable(${PROJECT_NAME} ${IMPLEMENTATION_SOURCES})

add_dependencies(${PROJECT_NAME} algorithms)

target_link_libraries(${PROJECT_NAME}  
  gtest
  gmock
  pthread
  algorithms
  # add any thrid party library which is referenced in test defined in this project
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${BINARY_DESTINATION_DIRECTORY})