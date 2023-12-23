cmake_minimum_required(VERSION 3.27)
project(C C)

set(CMAKE_C_STANDARD 23)

add_executable(C "Dynamic and static sequence table/Static linear list.c"
        "Dynamic and static sequence table/Dynamic linear list.c"
        "single linked list/single linked list.c"
        "single linked list/LinkList.c"
        "Dynamic and static sequence table/Sqlist.c"
        "single linked list/ClinkList.c")
