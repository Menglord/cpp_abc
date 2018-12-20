aux_source_directory(. UTILITY_SRCS)
add_executable(utility ${UTILITY_SRCS})
install(TARGETS utility DESTINATION ${BINARY_DIR})