cmake_minimum_required(VERSION 3.10)
project(8085Assembler C)

set(CMAKE_C_STANDARD 11)

include_directories(src include)

add_executable(assembler
    src/main.c
    src/lexer.c
    src/parser.c
    src/opcode_table.c
    src/assembler.c
)
