if(.. STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
    message(FATAL_ERROR "Prevented in-tree build. Please create a build directory outside of the source code and run \"cmake -S ${CMAKE_SOURCE_DIR} -B .\" from there")
endif()

cmake_minimum_required(VERSION 3.5)
project(CSTL_ForwardList VERSION 1.0.0 DESCRIPTION "A basic implementation of std::forward_list<T> from C++ STL in C" LANGUAGES C)

set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN TRUE)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Release' as none was specified.")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
endif()

message(STATUS "* CMake build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "* Current source dir: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "* Current binary dir: ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "* Current list dir: ${CMAKE_CURRENT_LIST_DIR}")

set(CSTL_FORWARD_LIST_PUBLIC_HEADERS
    include/BeginCode.h
    include/Iterator.h
    include/ForwardList.h
)

add_library(CSTL_ForwardList
    src/Node.c
    src/Iterator.c
    src/ForwardList.c
    src/Algorithms.c
)

find_package(CSTL_Exception REQUIRED)
find_package(CSTL_SmartPointer REQUIRED)
target_link_libraries(CSTL_ForwardList
    PUBLIC CSTL_Exception::CSTL_Exception
    PUBLIC CSTL_SmartPointer::CSTL_SmartPointer
)

set_target_properties(CSTL_ForwardList PROPERTIES
    VERSION ${CMAKE_PROJECT_VERSION}
    SOVERSION ${CMAKE_PROJECT_VERSION_MAJOR}
)

set(CSTL_FORWARD_LIST_INSTALL_INCLUDE_DIR "include/${CMAKE_PROJECT_NAME}")
target_include_directories(CSTL_ForwardList
    PUBLIC
    $<BUILD_INTERFACE:${CSTL_ForwardList_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CSTL_FORWARD_LIST_INSTALL_INCLUDE_DIR}>
)

set(CSTL_FORWARD_LIST_INSTALL_LIBRARY_DIR "lib")
set(CSTL_FORWARD_LIST_INSTALL_BINARY_DIR "bin")
install(
    TARGETS CSTL_ForwardList
    EXPORT ${CMAKE_PROJECT_NAME}Targets
    ARCHIVE DESTINATION ${CSTL_FORWARD_LIST_INSTALL_LIBRARY_DIR}
    LIBRARY DESTINATION ${CSTL_FORWARD_LIST_INSTALL_LIBRARY_DIR}
    RUNTIME DESTINATION ${CSTL_FORWARD_LIST_INSTALL_BINARY_DIR}
)

install(
    FILES ${CSTL_FORWARD_LIST_PUBLIC_HEADERS}
    DESTINATION ${CSTL_FORWARD_LIST_INSTALL_INCLUDE_DIR}
)

set(config_version_file "${CMAKE_CURRENT_LIST_DIR}/modules/cmake/${CMAKE_PROJECT_NAME}ConfigVersion.cmake")
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${config_version_file}
    VERSION ${CSTL_ForwardList_VERSION}
    COMPATIBILITY SameMajorVersion
)

export(
    EXPORT ${CMAKE_PROJECT_NAME}Targets
    FILE "${CMAKE_CURRENT_LIST_DIR}/modules/cmake/${CMAKE_PROJECT_NAME}Targets.cmake"
)

set(config_file "${CMAKE_CURRENT_LIST_DIR}/modules/cmake/${CMAKE_PROJECT_NAME}Config.cmake")
configure_package_config_file(
    "${CMAKE_CURRENT_LIST_DIR}/res/cmake/${CMAKE_PROJECT_NAME}Config.cmake.in"
    ${config_file}
    INSTALL_DESTINATION "${CMAKE_CURRENT_LIST_DIR}/modules/cmake"
)

set(CSTL_FORWARD_LIST_INSTALL_CONFIG_DIR "${CSTL_FORWARD_LIST_INSTALL_LIBRARY_DIR}/cmake/${CMAKE_PROJECT_NAME}")
install(
    EXPORT ${CMAKE_PROJECT_NAME}Targets
    FILE ${CMAKE_PROJECT_NAME}Targets.cmake
    NAMESPACE ${CMAKE_PROJECT_NAME}::
    DESTINATION ${CSTL_FORWARD_LIST_INSTALL_CONFIG_DIR}
)

set(install_config_file "${PROJECT_BINARY_DIR}/CMakeFiles/${CMAKE_PROJECT_NAME}Config.cmake")
configure_package_config_file(
    "${CMAKE_CURRENT_LIST_DIR}/res/cmake/${CMAKE_PROJECT_NAME}Config.cmake.in"
    ${install_config_file}
    INSTALL_DESTINATION ${CSTL_FORWARD_LIST_INSTALL_CONFIG_DIR}
)

install(
    FILES ${config_version_file} ${install_config_file}
    DESTINATION "${CSTL_FORWARD_LIST_INSTALL_CONFIG_DIR}"
)

# Testsing
if (DEFINED CSTL_FORWARD_LIST_NO_TESTS)
    return()
endif ()

include(CTest)
enable_testing()

set(CSTL_FORWARD_LIST_TEST_LIST
    TestCreation
    TestCapacity
    TestSwap
)

foreach (test ${CSTL_FORWARD_LIST_TEST_LIST})
    add_executable(${test} tests/${test}.c)
    target_link_libraries(${test} PRIVATE CSTL_ForwardList)

    add_test(
        NAME ${test}
        COMMAND $<TARGET_FILE:${test}>
    )

    set(MEMCHECK_ARGS
        --leak-check=full
        --track-origins=yes
        --show-leak-kinds=all
        --undef-value-errors=yes
        $<TARGET_FILE:${test}>
    )

    add_test(
        NAME MemCheck${test}
        COMMAND valgrind ${MEMCHECK_ARGS}
    )
endforeach ()
