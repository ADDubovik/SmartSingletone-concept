
set(SRC
	SingletoneClassic.h
	fake.cpp
)

add_library(${PROJECT_NAME}_lib ${SRC})

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(Classic01_correct   Classic01_correct.cpp)
add_executable(Classic02_incorrect Classic02_incorrect.cpp)
add_executable(Classic03_correct   Classic03_correct.cpp)
add_executable(Classic04_correct   Classic04_correct.cpp)
add_executable(Classic05_incorrect Classic05_incorrect.cpp)
