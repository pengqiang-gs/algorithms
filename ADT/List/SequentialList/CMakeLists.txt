# add libraries
add_library(SequentialList SequentialList.c)

# add testing executable
add_executable(SequentialListExample SequentialListExample.c)
target_link_libraries(SequentialListExample SequentialList)