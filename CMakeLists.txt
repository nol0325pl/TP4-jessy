cmake_minimum_required(VERSION 3.28.1)
project(CFONB_Analyzer C)

set(CMAKE_C_STANDARD 11)

add_executable(CFONB_Analyzer Source/main.c
        Source/cfonb_parser.c
        Include/cfonb_parser.h
        Source/cfonb_validator.c
        Include/cfonb_validator.h
        Source/cfonb_stats.c
        Include/cfonb_stats.h
        Source/cfonb_utils.c
        Include/cfonb_utils.h
        Include/cfonb_types.h
)
