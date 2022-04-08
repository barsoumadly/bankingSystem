cmake_minimum_required(VERSION 3.21)
project(BankingSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(BankingSystem main.cpp Account.cpp Account.h Bank.cpp Bank.h Application.cpp Application.h)
