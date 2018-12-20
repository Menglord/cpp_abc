include_directories(.)
aux_source_directory(. THREAD_SRCS)
add_executable(thread ${THREAD_SRCS})
install(TARGETS thread DESTINATION ${BINARY_DIR})