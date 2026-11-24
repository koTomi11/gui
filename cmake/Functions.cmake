
include(FetchContent)

function(load_external_lib)
    cmake_parse_arguments(LIB "" "NAME;TARGET;LINK_NAME;GIT_REPO;GIT_TAG;SOURCE_SUBDIR" "" ${ARGN})

    find_package(${LIB_NAME} QUIET)

    if(${LIB_NAME}_FOUND)
        message(STATUS "[LIB] ${LIB_NAME} megtalalva a rendszerben.")
    else()
        message(STATUS "[LIB] ${LIB_NAME} nem talalhato, letoltes Git-rol (${LIB_GIT_TAG})...")
        
        set(FETCH_ARGS
            GIT_REPOSITORY ${LIB_GIT_REPO}
            GIT_TAG        ${LIB_GIT_TAG}
            GIT_SHALLOW    TRUE
        )
        if(LIB_SOURCE_SUBDIR)
            list(APPEND FETCH_ARGS SOURCE_SUBDIR ${LIB_SOURCE_SUBDIR})
        endif()

        FetchContent_Declare(${LIB_NAME} ${FETCH_ARGS})
        FetchContent_MakeAvailable(${LIB_NAME})
    endif()

    if(LIB_TARGET AND LIB_LINK_NAME)
        target_link_libraries(${LIB_TARGET} PRIVATE ${LIB_LINK_NAME})
    endif()
endfunction()