cmake_minimum_required(VERSION 3.24)
project(Lab2SD)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab2SD main.cpp Colectie.cpp Colectie.h Test/Test_colectie.cpp Test/Test_colectie.h Tranzactie.cpp Tranzactie.h ATM.cpp ATM.h UI.cpp UI.h Service.cpp Service.h VectorDinamic.cpp VectorDinamic.h List.h Node.h)
