cmake_minimum_required(VERSION 3.15)
project(Assignment_04_Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment_04_Code
    BagInterface.h
    Include.h
    LinkedBag.cpp
    LinkedBag.h
    LinkedBag340.cpp
    LinkedBagClient340.cpp
    Node.cpp
    Node.h
        PartC_SmartPointers/PartC_SmartPointers.cpp
        PartC_SmartPointers/SPLinkedBag.cpp
        PartC_SmartPointers/SPLinkedBag.h
        PartC_SmartPointers/Include_SmartPointers.h

        PartC_SmartPointers/SPNode.cpp
        PartC_SmartPointers/SPNode.h
        )
