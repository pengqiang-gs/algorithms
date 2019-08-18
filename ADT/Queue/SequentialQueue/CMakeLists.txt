add_library(SequentialQueue SequentialQueue.c)

add_executable(SequentialQueueExample SequentialQueueExample.c)
target_link_libraries(SequentialQueueExample SequentialQueue)
