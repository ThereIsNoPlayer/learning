cmake_minimum_required(VERSION 4.0)
project(C C)

set(CMAKE_C_STANDARD 99)

add_executable(C main.c
        1.c
        1.h
        test.c
        test.h
        zuoye1.c
        zuoye1.h
        zhizhenlianxi.c
        zhizhen2.c
        zhizhen3.c
        zhizhen3.c
        zhizhen4.c
        jiegouti/jiegouti1.c)
add_executable(new_target jiegouti/jiegouti1.c)
