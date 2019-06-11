cmake_minimum_required(VERSION 3.7)
project(SmartSingletoneConcept)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set (BRAND_FULLNAME "SmartSingletoneConcept")
set (BRAND_COMPANYNAME "ADDubovik")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(src)
