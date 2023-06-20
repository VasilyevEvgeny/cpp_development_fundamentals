cmake_minimum_required(VERSION 3.14)
project(4_brown_belt)

set(CMAKE_CXX_STANDARD 14)

##################
##### week 1 #####
##################

add_executable(1_01 week_1/1_01/hash_set.cpp)
add_executable(1_02 week_1/1_02/set_iterator_next.cpp)
add_executable(1_03 week_1/1_03/hash_point.cpp)
add_executable(1_04 week_1/1_04/hash_point.cpp)
add_executable(1_05 week_1/1_05/hash_point.cpp)


##################
##### week 2 #####
##################

add_executable(2_01 week_2/2_01/xml.cpp week_2/2_01/spendings_xml.cpp)
add_executable(2_02 week_2/2_02/json.cpp week_2/2_02/spendings_json.cpp)
add_executable(2_03 week_2/2_03/ini.cpp week_2/2_03/spendings_ini.cpp)
add_executable(2_04 week_2/2_04/ini.cpp week_2/2_04/refactoring.cpp)
