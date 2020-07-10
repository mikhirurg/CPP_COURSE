cmake_minimum_required(VERSION 3.15)
project(CPP_COURSE)

set(CMAKE_CXX_STANDARD 14)

if (FALSE)
# BLOCK2

#TASK 2_5_1
add_executable(str_len BLOCK2/str_len.cpp)

#TASK 2_5_2
add_executable(concat_str BLOCK2/concat_str.cpp)

#TASK 2_5_3
add_executable(substring_search BLOCK2/substring_search.cpp)

#TASK 2_6_1
add_executable(resize_arr BLOCK2/resize_arr.cpp)

#TASK 2_6_2
add_executable(getline BLOCK2/GetLine.cpp)

#TASK 2_7_1
add_executable(matrix BLOCK2/matrix.cpp)

#TASK 2_7_2
add_executable(swap_min BLOCK2/SwapMin.cpp)

#BLOCK3

#TASK 3_3_1
add_executable(Str BLOCK3/CString.cpp)

#TASK 3_5_1
add_executable(Cls BLOCK3/cls_task.cpp)
endif()

#BLOCK4

#TASK 4_1_1
add_executable(RPG BLOCK4/RPG.cpp)

#TASK 4_1_2
add_executable(Foo BLOCK4/FooTask.cpp)

#TASK 4_3_1
add_executable(Expr BLOCK4/Expr.cpp)