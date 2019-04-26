project(algorithms)

add_library(${PROJECT_NAME} STATIC
    implementation/sort/bubble_sort.cpp
    implementation/sort/bucket_sort.cpp
    implementation/sort/counting_sort.cpp
    implementation/sort/cycle_sort.cpp
    implementation/sort/heap_sort.cpp
    implementation/sort/insertion_sort.cpp
    implementation/sort/merge_sort.cpp
    implementation/sort/odd_even_sort.cpp
    implementation/sort/quick_sort.cpp
    implementation/sort/radix_sort.cpp
    implementation/sort/selection_sort.cpp
)

target_include_directories(${PROJECT_NAME} 
  # Expose interface folder as public library interface
  PUBLIC interface
  # hide library implementation from outside
  PRIVATE implementation)

# Installation folder. Run 'make install' to install this project in specified folder
install(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION ${BINARY_DESTINATION_DIRECTORY})