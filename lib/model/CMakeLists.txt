
set(SOURCES Radar.cpp IFF.cpp FiringUnit.cpp)

add_library(model ${SOURCES})
target_include_directories(model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(model infra)
