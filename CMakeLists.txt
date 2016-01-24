cmake_minimum_required(VERSION 3.3)
project(GKOM_BattleTank)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


#########################################################
# FIND GLUT
#########################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)
#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#########################################################
# Include Files
#########################################################
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
link_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set(SOURCE_FILES
        Model/sources/Camera.cpp
        Model/headers/Camera.h
        Model/sources/Environment.cpp
        Model/headers/Environment.h
        Logic/sources/Game.cpp
        Logic/headers/Game.h
        Main.cpp
        Model/sources/Missle.cpp
        Model/headers/Missle.h
        Model/sources/SceneObject.cpp
        Model/headers/SceneObject.h
        Model/sources/Sun.cpp
        Model/headers/Sun.h
        Model/sources/Tank.cpp
        Model/headers/Tank.h
        Model/headers/Vector3D.h
        Model/sources/Tree.cpp
        Model/headers/Tree.h
        Assets/sources/Assets.cpp
        Assets/headers/Assets.h
        Assets/sources/ComputerOpponent.cpp
        Assets/headers/ComputerOpponent.h Assets/sources/TextureLoader.cpp Assets/headers/TextureLoader.h)

add_executable(GKOM_BattleTank ${SOURCE_FILES})

target_link_libraries(GKOM_BattleTank SOIL ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )