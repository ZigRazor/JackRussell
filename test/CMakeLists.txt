option(CODE_COVERAGE "Enable coverage reporting" OFF)

# Force dynamic linking since MSVC now links C runtimes dynamically by default
set(gtest_force_shared_crt on)

if(CODE_COVERAGE)
	message( "Code Coverage Enabled" )
	add_compile_options(
		-O0  #no optimization
		-g   #generate debug info
		--coverage #set coverage flag
		-fprofile-arcs
		-ftest-coverage
		-fPIC
	)
	link_libraries(
		"gcov"
		"-fprofile-arcs"
		"--coverage"
	)

endif(CODE_COVERAGE)


include(${CPM_DOWNLOAD_LOCATION})

CPMAddPackage(
    NAME googletest
    GITHUB_REPOSITORY google/googletest
    GIT_TAG origin/main
    OPTIONS "gtest_forced_shared_crt ON CACHE BOOL FORCE"
)

file (GLOB TEST_FILES "*.cpp" "*.hpp" "*.h")
add_executable(jackrussell_test_exe ${TEST_FILES})

target_compile_definitions(jackrussell_test_exe
    PUBLIC WITH_COMPRESSION
)

target_include_directories(jackrussell_test_exe
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
    PUBLIC "${PROJECT_SOURCE_DIR}/test"
	Labrador
)

target_link_libraries(jackrussell_test_exe
    PUBLIC GTest::gtest_main
	GTest::gtest
	GTest::gmock
    pthread
	Labrador
	JackRussell
)

add_test(AbstractTopicTest jackrussell_test_exe --gtest_filter=AbstractTopicTest*)
add_test(TopicManagerTest jackrussell_test_exe --gtest_filter=TopicManagerTest*)
   

