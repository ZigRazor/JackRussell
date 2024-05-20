cmake_minimum_required(VERSION 3.16)

project (JackRussell VERSION "0.0.1" LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file( GLOB SRC_FILES "src/*.cpp" )

message ( ERROR "SRC_FILES: ${SRC_FILES}" )

option(DEBUG "Enable Debug" OFF)
if(DEBUG)
	add_compile_options(
		-O0  #no optimization
		-g   #generate debug info
	)

endif(DEBUG)

# set up CPM.cmake
if(CPM_SOURCE_CACHE)
	set(CPM_DOWNLOAD_LOCATION "${CPM_SOURCE_CACHE}/cpm/CPM.cmake")
elseif(DEFINED ENV{CPM_SOURCE_CACHE})
	set(CPM_DOWNLOAD_LOCATION "$ENV{CPM_SOURCE_CACHE}/cpm/CPM.cmake")
else()
	set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM.cmake")
endif()

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
	message(STATUS "Downloading CPM.cmake to ${CPM_DOWNLOAD_LOCATION}")
	file(DOWNLOAD
    	https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/CPM.cmake
    	${CPM_DOWNLOAD_LOCATION}
	)
endif()

include(${CPM_DOWNLOAD_LOCATION})

CPMAddPackage(
    NAME Labrador
    GITHUB_REPOSITORY ZigRazor/Labrador
    GIT_TAG origin/main
)



add_library(    ${PROJECT_NAME} SHARED
                ${SRC_FILES}
                )

target_include_directories( ${PROJECT_NAME} PUBLIC 
                            include/
                            Labrador
                            )

target_link_libraries(  ${PROJECT_NAME} PUBLIC Labrador)

file( GLOB HEADERS_FILES "include/*.h*" )

#message ( ERROR "HEADERS_FILES: ${HEADERS_FILES}" )

target_sources ( ${PROJECT_NAME} INTERFACE ${HEADERS_FILES} ${SRC_FILES} )
target_compile_features( ${PROJECT_NAME} INTERFACE cxx_std_20 )
target_include_directories( ${PROJECT_NAME} INTERFACE include/ )

option(TEST "Enable Test" OFF)
if(TEST)
	enable_testing()
	add_subdirectory("test")
endif(TEST)
option(EXAMPLE "Enable Example" OFF)
if(EXAMPLE)
	add_subdirectory("example")
endif(EXAMPLE)