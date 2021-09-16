cmake_minimum_required(VERSION 3.20)
project(CppDemo)

set(CMAKE_CXX_STANDARD 14)


# main
add_executable(
        ###### main ######
        cpp_demo main.cpp
        ###### About Cpp Primer ######
        source/Sales_item.h source/CppPrimerTest.cpp source/CppPrimerTest.h


)

