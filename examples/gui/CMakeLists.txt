set(SRCS
main.cpp irenderer.h glutrenderwin.cpp glutrenderwin.h
baserenderer.cpp baserenderer.h ikeyboardhandler.h
menurenderer.cpp menurenderer.h
inputconsole.cpp inputconsole.h)

find_package(OpenGL REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} )
set(CMAKE_BUILD_TYPE Debug)

add_executable(gui ${SRCS})

# if we are building for visual studio, deploy glut 
# manually from the extern/ folder
if(MSVC)
	set(GLUT_DIR ${CMAKE_SOURCE_DIR}/extern/win/glut)

	file(MAKE_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}/Debug)
	file(MAKE_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}/Release)
	file(COPY ${GLUT_DIR}/glut32.dll DESTINATION ${EXECUTABLE_OUTPUT_PATH}/Debug)
	file(COPY ${GLUT_DIR}/glut32.dll DESTINATION ${EXECUTABLE_OUTPUT_PATH}/Release)
	
	include_directories(${GLUT_DIR})
	target_link_libraries(gui ${GLUT_DIR}/glut32.lib)

	set(CMAKE_EXE_LINKER_FLAGS "/SAFESEH:NO")

# otherwise, use the standard find_package approach
else (MSVC)
	find_package(GLUT REQUIRED)	
	include_directories(${GLUT_INCLUDE_DIR})
	target_link_libraries(gui ${GLUT_LIBRARY})
endif(MSVC)


target_link_libraries(gui ${OPENGL_LIBRARIES} libSimpleFsm)
