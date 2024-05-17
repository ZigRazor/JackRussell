add_executable(  JackRussellExample1 main.cpp
                )

target_include_directories( JackRussellExample1 PUBLIC 
                            "${PROJECT_SOURCE_DIR}/include"
                            Labrador
                            )

target_link_libraries(  JackRussellExample1 PUBLIC 
                        pthread
                        Labrador
                        JackRussell)
