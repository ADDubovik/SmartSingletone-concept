cmake_minimum_required(VERSION 3.7)
project(SmartSingletonConcept)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set (BRAND_FULLNAME "SmartSingletonConcept")
set (BRAND_COMPANYNAME "ADDubovik")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(src/SingleThreaded)
