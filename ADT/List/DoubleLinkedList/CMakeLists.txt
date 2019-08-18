# add libraries
add_library(DoubleLinkedList DoubleLinkedList.c)

# add testing executable
add_executable(DoubleLinkedListExample DoubleLinkedListExample.c)
target_link_libraries(DoubleLinkedListExample DoubleLinkedList)