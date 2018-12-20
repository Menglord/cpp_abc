aux_source_directory(. FUNCTION_OBJECT_SRCS)
add_executable(function_object ${FUNCTION_OBJECT_SRCS})
install(TARGETS function_object DESTINATION ${BINARY_DIR})