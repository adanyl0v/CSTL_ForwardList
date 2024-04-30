include(CTest)
enable_testing()

set(TEST_LIST
    TestCreation
    TestCapacity
    TestSwap
)

foreach (test ${TEST_LIST})
    add_executable(${test} ${PROJECT_SOURCE_DIR}/tests/${test}.c)
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
