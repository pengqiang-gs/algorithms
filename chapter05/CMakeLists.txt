# add libraries
add_library(int_seq_array int_seq_array.c)

# add testing demo
add_executable(int_seq_array_demo int_seq_array_demo.c)
target_link_libraries(int_seq_array_demo int_seq_array)
