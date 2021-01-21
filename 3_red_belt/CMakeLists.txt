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
