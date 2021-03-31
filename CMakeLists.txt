cmake_minimum_required(VERSION 3.17)
project(c_test)

set(CMAKE_CXX_STANDARD 14)

set(Headers helper.h)
add_executable(c_test send_recv.c ping_pong.c ring.c check_status.c probe.c random_walk.cpp my_bcast.c avg.c reduce_avg.c
        reduce_stddev.c)