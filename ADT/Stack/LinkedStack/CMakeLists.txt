add_library(LinkedStack LinkedStack.c)

add_executable(LinkedStackExample LinkedStackExample.c)
target_link_libraries(LinkedStackExample LinkedStack)

