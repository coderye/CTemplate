set(LIB_SOURCES
	path.c
)

set(MAIN_SOURCES
	main.c
)

set(HEADERS 
	${CONFIG_HEADER}
	path.h
)

add_library(path STATIC ${LIB_SOURCES} ${HEADERS})

add_executable(main ${HEADERS} ${MAIN_SOURCES})
target_link_libraries(main path)

install(TARGETS path
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/path.h DESTINATION include)
