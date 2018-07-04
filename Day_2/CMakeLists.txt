project (day_2)

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
set(SOURCE_FILES main.cpp)
add_executable(day_2 ${SOURCE_FILES})
target_link_libraries( day_2 ${OpenCV_LIBS} )
