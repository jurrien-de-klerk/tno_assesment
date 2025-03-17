
set(SOURCES SimulationDriver.cpp)

add_library(infra ${SOURCES})
target_include_directories(infra PUBLIC .)
