
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

add_executable(Classic_Step1_correct   Classic_Step1_correct.cpp)
add_executable(Classic_Step2_incorrect Classic_Step2_incorrect.cpp)
add_executable(Classic_Step3_correct   Classic_Step3_correct.cpp)

add_executable(Shared_Step1_correct   Shared_Step1_correct.cpp)
add_executable(Shared_Step2_incorrect Shared_Step2_incorrect.cpp)
add_executable(Shared_Step3_correct   Shared_Step3_correct.cpp)
add_executable(Shared_Step4_incorrect Shared_Step4_incorrect.cpp)

add_executable(Weak_Step1_correct   Weak_Step1_correct.cpp)
add_executable(Weak_Step2_incorrect Weak_Step2_incorrect.cpp)


set_property(TARGET Classic_Step1_correct   PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Classic_Step2_incorrect PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Classic_Step3_correct PROPERTY FOLDER "SingleThreaded")

set_property(TARGET Shared_Step1_correct   PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Shared_Step2_incorrect PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Shared_Step3_correct   PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Shared_Step4_incorrect PROPERTY FOLDER "SingleThreaded")

set_property(TARGET Weak_Step1_correct   PROPERTY FOLDER "SingleThreaded")
set_property(TARGET Weak_Step2_incorrect PROPERTY FOLDER "SingleThreaded")
