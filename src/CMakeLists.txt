set(NAME TChip8)

file(GLOB_RECURSE SRC
"*.hpp"
"*.cpp"
"*.c"
)

add_executable(${NAME}
	WIN32
	${SRC}
)


target_link_libraries(${NAME}
	${TEMU_LIBS}
)
include_directories(
	${TEMU_INCLUDES}
)
