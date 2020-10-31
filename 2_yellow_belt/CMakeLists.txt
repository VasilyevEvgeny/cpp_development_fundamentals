cmake_minimum_required(VERSION 3.14)
project(2_yellow_belt)

set(CMAKE_CXX_STANDARD 14)

##################
##### week 1 #####
##################

add_executable(1_01 week_1/1_01/avg_temperature2.cpp)
add_executable(1_02 week_1/1_02/blocks_mass.cpp)
add_executable(1_03 week_1/1_03/regions.cpp)
add_executable(1_04 week_1/1_04/tracker.cpp)
# !!!!!!!!!! add_executable(1_05 week_1/1_05/sqr_all.cpp)
add_executable(1_06 week_1/1_06/element_reference.cpp)

##################
##### week 2 #####
##################

add_executable(2_01 week_2/2_01/starter.cpp)
add_executable(2_02 week_2/2_02/test_equation.cpp)
add_executable(2_03 week_2/2_03/test_person.cpp)
add_executable(2_04 week_2/2_04/test_rational.cpp)
add_executable(2_05 week_2/2_05/test_palindrome.cpp)

##################
##### week 3 #####
##################

add_executable(3_01 week_3/3_01/realizations_of_functions.cpp week_3/3_01/sum_reverse_sort.h)
add_executable(3_02 week_3/3_02/phone_number.cpp week_3/3_02/phone_number.h)
add_executable(3_03 week_3/3_03/rectangle.cpp week_3/3_03/rectangle.h)
# !!!!!!!!!!! add_executable(3_04 week_3/3_04/rectangle.cpp week_3/3_03/rectangle.h)

##################
##### week 4 #####
##################

add_executable(4_01 week_4/4_01/part_of_vector.cpp)
add_executable(4_02 week_4/4_02/part_of_set.cpp)
add_executable(4_03 week_4/4_03/split_into_words.cpp)
add_executable(4_04_1 week_4/4_04/merge_sort_2.cpp)
add_executable(4_04_2 week_4/4_04/merge_sort_3.cpp)
add_executable(4_05 week_4/4_05/remove_duplicates.cpp)
add_executable(4_06 week_4/4_06/permutations.cpp)
add_executable(4_07 week_4/4_07/demography.cpp)
# !!!! add_executable(4_08 week_4/4_08/demography.cpp)