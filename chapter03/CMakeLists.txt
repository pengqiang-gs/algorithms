# add libraries
add_library(int_seq_stack int_seq_stack.c)
add_library(int_link_stack int_link_stack.c)
add_library(int_link_queue int_link_queue.c)

# add testing demo
add_executable(decimal_to_octal decimal_to_octal.c)
target_link_libraries(decimal_to_octal int_seq_stack)

add_executable(bracket_match bracket_match.c)
target_link_libraries(bracket_match int_link_stack)

add_executable(stand_in_line stand_in_line.c)
target_link_libraries(stand_in_line int_link_queue)

