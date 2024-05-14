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

add_library(    ${PROJECT_NAME} SHARED
                ${SRC_FILES}
                )

target_include_directories( ${PROJECT_NAME} PUBLIC 
                            include/
                            dependencies/Labrador/include
                            )

target_link_libraries(  ${PROJECT_NAME} PUBLIC )

#add_subdirectory("examples")