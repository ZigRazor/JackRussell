add_executable(  JackRussellExample2 main.cpp
                )

target_include_directories( JackRussellExample2 PUBLIC 
                            "${PROJECT_SOURCE_DIR}/include"
                            Labrador
                            )

target_link_libraries(  JackRussellExample2 PUBLIC 
                        pthread
                        Labrador
                        JackRussell)
