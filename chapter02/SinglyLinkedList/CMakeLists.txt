# add libraries
add_library(SinglyLinkedList SinglyLinkedList.c)

# add testing executable
add_executable(SinglyLinkedListExample SinglyLinkedListExample.c)
target_link_libraries(SinglyLinkedListExample SinglyLinkedList)