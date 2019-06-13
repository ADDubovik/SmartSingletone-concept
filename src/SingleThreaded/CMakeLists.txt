
set(SRC
	SingletonClassic.h
	SingletonPayload.h
	SingletonShared.h
	SingletonWeak.h
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
add_executable(Classic_Example2_Step3_correct   Classic_Example2_Step3_correct.cpp)

add_executable(Shared_Example1_Step1_correct   Shared_Example1_Step1_correct.cpp)
add_executable(Shared_Example1_Step2_incorrect Shared_Example1_Step2_incorrect.cpp)
add_executable(Shared_Example1_Step3_correct   Shared_Example1_Step3_correct.cpp)
add_executable(Shared_Example1_Step4_incorrect Shared_Example1_Step4_incorrect.cpp)

add_executable(Weak_Example1_Step1_correct   Weak_Example1_Step1_correct.cpp)
add_executable(Weak_Example1_Step2_incorrect Weak_Example1_Step2_incorrect.cpp)


set_property(TARGET Classic_Example1_Step1_correct   PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Classic_Example1_Step2_incorrect PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Classic_Example1_Step3_correct   PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Classic_Example2_Step1_correct   PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Classic_Example2_Step2_incorrect PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Classic_Example2_Step3_correct PROPERTY FOLDER "SingleThreaded")

set_property(TARGET Shared_Example1_Step1_correct   PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Shared_Example1_Step2_incorrect PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Shared_Example1_Step3_correct   PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Shared_Example1_Step4_incorrect PROPERTY FOLDER "SingleThreaded")

set_property(TARGET Weak_Example1_Step1_correct   PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Weak_Example1_Step2_incorrect PROPERTY FOLDER "SingleThreaded")
