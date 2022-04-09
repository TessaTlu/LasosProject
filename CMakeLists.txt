cmake_minimum_required(VERSION 3.20)
project(LasosProject)

set(CMAKE_CXX_STANDARD 23)
set(BOOST_ROOT "/opt/homebrew/Cellar/boost")
find_package(Boost 1.76.0 COMPONENTS regex REQUIRED)

if (Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
endif ()
add_executable(LasosProject main.cpp internal/lasos/token/LasosToken.cpp internal/lasos/token/LasosToken.h pkg/strings/Strings.cpp pkg/strings/Strings.h)
if (Boost_FOUND)
    target_link_libraries(LasosProject ${Boost_LIBRARIES})
endif ()

