aux_source_directory(. TEMPLATE_SRCS)
add_executable(template ${TEMPLATE_SRCS})
install(TARGETS template DESTINATION ${BINARY_DIR})