
set(SRC
	SingletoneClassic.h
	fake.cpp
)

add_library(${PROJECT_NAME}_lib ${SRC})

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(Classic_Example1_Step1_correct   Classic_Example1_Step1_correct.cpp)
add_executable(Classic_Example1_Step2_incorrect Classic_Example1_Step2_incorrect.cpp)
add_executable(Classic_Example1_Step3_correct   Classic_Example1_Step3_correct.cpp)
add_executable(Classic_Example2_Step1_correct   Classic_Example2_Step1_correct.cpp)
add_executable(Classic_Example2_Step2_incorrect Classic_Example2_Step2_incorrect.cpp)
