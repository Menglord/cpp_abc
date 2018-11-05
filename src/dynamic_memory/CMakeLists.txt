aux_source_directory(. DYNAMIC_MEMORY_SRCS)
add_executable(dynamic_memory ${DYNAMIC_MEMORY_SRCS})
install(TARGETS dynamic_memory DESTINATION ${BINARY_DIR})