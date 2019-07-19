cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 14)

# Installaton folder for built targets. TO install a target run 'make install' command.
set(BINARY_DESTINATION_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

add_subdirectory(src)
add_subdirectory(test)