set(SOURCE_FILES sqr.cpp sqr.h main.cpp nmtranpreproc.cpp nmtranpreproc.h)

add_library (Sqr ${SOURCE_FILES})

add_executable (demo ${SOURCE_FILES})

target_link_libraries (demo Sqr)
