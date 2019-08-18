add_library(LinkedQueue LinkedQueue.c)

add_executable(LinkedQueueExample LinkedQueueExample.c)
target_link_libraries(LinkedQueueExample LinkedQueue)
