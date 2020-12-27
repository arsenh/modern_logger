project(logger)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PRIVATE
    logger.hpp logger.cpp logger.icpp logger_file.hpp logger_file.cpp
)
