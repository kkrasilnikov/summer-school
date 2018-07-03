project (day_1)

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
set(SOURCE_FILES main.cpp)
add_executable(day_1 ${SOURCE_FILES})
target_link_libraries( day_1 ${OpenCV_LIBS} )
