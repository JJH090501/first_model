cmake_minimum_required(VERSION 3.20)

project(word_chain_ai)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(word_chain_ai
    main.cpp
    WordChain.cpp
)