# add libraries
add_library(int_seq_list int_seq_list.c)
add_library(int_single_list int_single_list.c)
add_library(int_double_list int_double_list.c)

# add testing demo
add_executable(int_seq_list_demo int_seq_list_demo.c)
target_link_libraries(int_seq_list_demo int_seq_list)

add_executable(int_single_list_demo int_single_list_demo.c)
target_link_libraries(int_single_list_demo int_single_list)

add_executable(int_double_list_demo int_double_list_demo.c)
target_link_libraries(int_double_list_demo int_double_list)