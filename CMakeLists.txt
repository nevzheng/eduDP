cmake_minimum_required(VERSION 3.19)
project(eduDP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set Global Compilation Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra")

add_executable(A_frog1 src/A_frog1.cpp)
add_executable(B_frog2 src/B_frog2.cpp)
add_executable(C_vacation src/C_vacation.cpp)
add_executable(D_knapsack1 src/D_knapsack1.cpp)
add_executable(E_knapsack2 src/E_knapsack2.cpp)

add_executable(G_longest_path src/G_longest_path.cpp)
add_executable(H_grid1 src/H_grid1.cpp)

