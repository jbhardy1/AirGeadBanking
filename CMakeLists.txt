cmake_minimum_required(VERSION 3.15)
project(airgead_banking)

set(CMAKE_CXX_STANDARD 14)

add_executable(airgead_banking main.cpp ReportGenerator.cpp ReportGenerator.h Calculations.cpp Calculations.h DataInput.cpp DataInput.h InvestmentInfo.cpp InvestmentInfo.h)
