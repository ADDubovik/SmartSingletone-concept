
set(SRC
	SingletoneClassic.h
	fake.cpp
)

add_library(${PROJECT_NAME}_lib ${SRC})

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(DemoClassicCorrect01 DemoClassicCorrect01.cpp)
