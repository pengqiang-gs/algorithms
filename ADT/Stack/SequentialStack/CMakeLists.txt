add_library(SequentialStack SequentialStack.c)

add_executable(SequentialStackExample SequentialStackExample.c)
target_link_libraries(SequentialStackExample SequentialStack)

