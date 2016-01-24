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
        Model/Camera.cpp
        Model/Camera.h
        Model/Environment.cpp
        Model/Environment.h
        Logic/Game.cpp
        Logic/Game.h
        Main.cpp
        Model/Missle.cpp
        Model/Missle.h
        Model/SceneObject.cpp
        Model/SceneObject.h
        Model/Sun.cpp
        Model/Sun.h
        Model/Tank.cpp
        Model/Tank.h
        Model/Vector3D.h
        Model/Tree.cpp
        Model/Tree.h
        Assets/Assets.cpp
        Assets/Assets.h
        Logic/ComputerOpponent.cpp
        Logic/ComputerOpponent.h Assets/TextureLoader.cpp Assets/TextureLoader.h)

add_executable(GKOM_BattleTank ${SOURCE_FILES})

target_link_libraries(GKOM_BattleTank SOIL ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )