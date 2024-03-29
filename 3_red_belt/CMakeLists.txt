cmake_minimum_required(VERSION 3.14)
project(3_red_belt)

set(CMAKE_CXX_STANDARD 14)

##################
##### week 1 #####
##################

add_executable(1_01 week_1/1_01/macros_log.cpp week_1/1_01/test_runner.h)
add_executable(1_02 week_1/1_02/sort_by.cpp week_1/1_02/airline_ticket.h week_1/1_02/test_runner.h)
add_executable(1_03 week_1/1_03/update_field.cpp week_1/1_03/airline_ticket.h week_1/1_03/test_runner.h)
add_executable(1_04 week_1/1_04/bad_macros.cpp week_1/1_04/test_runner.h)
add_executable(1_05 week_1/1_05/uniq_id.cpp)
add_executable(1_06 week_1/1_06/table.cpp week_1/1_06/test_runner.h)
add_executable(1_07 week_1/1_07/deque.cpp)
add_executable(1_08 week_1/1_08/paginator.cpp week_1/1_08/test_runner.h)

##################
##### week 2 #####
##################

add_executable(2_01 week_2/2_01/student_sorting.cpp week_2/2_01/student.h week_2/2_01/test_runner.h)
add_executable(2_02 week_2/2_02/learner.cpp)
add_executable(2_03 week_2/2_03/express.cpp)
add_executable(2_04 week_2/2_04/ebook.cpp)
add_executable(2_05 week_2/2_05/hotels.cpp)

##################
##### week 3 #####
##################

add_executable(3_01 week_3/3_01/pool.cpp week_3/3_01/test_runner.h)
add_executable(3_02 week_3/3_02/swap_sort_copy.cpp week_3/3_02/test_runner.h)
add_executable(3_03 week_3/3_03/simple_vector.cpp week_3/3_03/simple_vector.h week_3/3_03/test_runner.h)
add_executable(3_04 week_3/3_04/linked_list.cpp week_3/3_03/test_runner.h)

##################
##### week 4 #####
##################

add_executable(4_01 week_4/4_01/sportsmen.cpp)
add_executable(4_02 week_4/4_02/stack_vector.cpp week_4/4_02/stack_vector.h week_4/4_02/profile.h week_4/4_02/test_runner.h)
add_executable(4_03 week_4/4_03/translator.cpp week_4/4_03/profile.h week_4/4_03/test_runner.h)

add_executable(4_04 week_4/4_04/airport_counter.cpp week_4/4_03/profile.h week_4/4_03/test_runner.h)
set_property(TARGET 4_04 PROPERTY CXX_STANDARD 17)

add_executable(4_05 week_4/4_05/text_editor.cpp week_4/4_05/profile.h week_4/4_05/test_runner.h)
set_property(TARGET 4_05 PROPERTY CXX_STANDARD 17)

add_executable(4_06 week_4/4_06/server_stats.cpp week_4/4_06/stats.cpp week_4/4_06/stats.h
        week_4/4_06/http_request.h week_4/4_06/profile.h week_4/4_06/test_runner.h)
set_property(TARGET 4_06 PROPERTY CXX_STANDARD 17)

##################
##### week 5 #####
##################

add_executable(5_01 week_5/5_01/josephs_permutation.cpp)

add_executable(5_02 week_5/5_02/ground_heavy_strings.cpp)

add_executable(5_03 week_5/5_03/simple_vector_copy_assignment.cpp)

add_executable(5_04 week_5/5_04/split_into_sentences.cpp)

add_executable(5_05 week_5/5_05/simple_vector_2.cpp)

add_executable(5_06 week_5/5_06/merge_sort_3.cpp)

add_executable(5_07 week_5/5_07/priority_collection_2.cpp)

add_executable(5_08 week_5/5_08/matrix_sum_1.cpp)

add_executable(5_09 week_5/5_09/explore_key_words.cpp)

add_executable(5_10 week_5/5_10/synchronized.cpp)

add_executable(5_11 week_5/5_11/concurrent_map.cpp)


##################
##### week 6 #####
##################

add_executable(6_01
        week_6/6_01/main.cpp
        week_6/6_01/parse.cpp
        week_6/6_01/profile.cpp
        week_6/6_01/search_server.cpp
)

add_executable(6_02
        week_6/6_02/main.cpp
        week_6/6_02/parse.cpp
        week_6/6_02/search_server.cpp
)