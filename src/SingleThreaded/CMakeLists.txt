
set(SRC
	CallbackPayload.h
	Payload.h
	SingletonClassic.h
	SingletonShared.h
	SingletonWeak.h
	SomethingWithVeryImportantDestructor.h
	fake.cpp
)

add_library(${PROJECT_NAME}_lib ${SRC})

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(Classic_Example1_correct   Classic_Example1_correct.cpp)
add_executable(Classic_Example2_incorrect Classic_Example2_incorrect.cpp)
add_executable(Classic_Example3_correct   Classic_Example3_correct.cpp)

add_executable(Shared_Example1_correct   Shared_Example1_correct.cpp)
add_executable(Shared_Example2_incorrect Shared_Example2_incorrect.cpp)
add_executable(Shared_Example3_correct   Shared_Example3_correct.cpp)
add_executable(Shared_Example4_incorrect Shared_Example4_incorrect.cpp)
add_executable(Shared_Example5_incorrect Shared_Example5_incorrect.cpp)

add_executable(Weak_Example1_correct   Weak_Example1_correct.cpp)
add_executable(Weak_Example2_correct   Weak_Example2_correct.cpp)
add_executable(Weak_Example3_incorrect Weak_Example3_incorrect.cpp)


set_property(TARGET Classic_Example1_correct   PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Classic_Example2_incorrect PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Classic_Example3_correct PROPERTY FOLDER "SingleThreaded")

set_property(TARGET Shared_Example1_correct   PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Shared_Example2_incorrect PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Shared_Example3_correct   PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Shared_Example4_incorrect PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Shared_Example5_incorrect PROPERTY FOLDER "SingleThreaded")

set_property(TARGET Weak_Example1_correct   PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Weak_Example2_correct PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Weak_Example3_incorrect PROPERTY FOLDER "SingleThreaded")
