# Install script for directory: /home/mischa/CLionProjects/untitled/vendor/assimp/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.2.5" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so.5.2.5"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so.5"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/mischa/CLionProjects/untitled/cmake-build-debug-coverage/vendor/assimp/bin/libassimpd.so.5.2.5"
    "/home/mischa/CLionProjects/untitled/cmake-build-debug-coverage/vendor/assimp/bin/libassimpd.so.5"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so.5.2.5"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so.5"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.2.5" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/mischa/CLionProjects/untitled/cmake-build-debug-coverage/vendor/assimp/bin/libassimpd.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/anim.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/aabb.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/ai_assert.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/camera.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/color4.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/color4.inl"
    "/home/mischa/CLionProjects/untitled/cmake-build-debug-coverage/vendor/assimp/code/../include/assimp/config.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/ColladaMetaData.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/commonMetaData.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/defs.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/cfileio.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/light.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/material.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/material.inl"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/matrix3x3.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/matrix3x3.inl"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/matrix4x4.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/matrix4x4.inl"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/mesh.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/ObjMaterial.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/pbrmaterial.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/GltfMaterial.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/postprocess.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/quaternion.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/quaternion.inl"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/scene.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/metadata.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/texture.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/types.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/vector2.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/vector2.inl"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/vector3.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/vector3.inl"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/version.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/cimport.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/AssertHandler.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/importerdesc.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/Importer.hpp"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/DefaultLogger.hpp"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/ProgressHandler.hpp"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/IOStream.hpp"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/IOSystem.hpp"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/Logger.hpp"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/LogStream.hpp"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/NullLogger.hpp"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/cexport.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/Exporter.hpp"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/DefaultIOStream.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/DefaultIOSystem.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/ZipArchiveIOSystem.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/SceneCombiner.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/fast_atof.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/qnan.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/BaseImporter.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/Hash.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/MemoryIOWrapper.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/ParsingUtils.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/StreamReader.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/StreamWriter.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/StringComparison.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/StringUtils.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/SGSpatialSort.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/GenericProperty.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/SpatialSort.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/SkeletonMeshBuilder.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/SmallVector.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/SmoothingGroups.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/SmoothingGroups.inl"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/StandardShapes.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/RemoveComments.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/Subdivision.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/Vertex.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/LineSplitter.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/TinyFormatter.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/Profiler.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/LogAux.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/Bitmap.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/XMLTools.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/IOStreamBuffer.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/CreateAnimMesh.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/XmlParser.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/BlobIOSystem.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/MathFunctions.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/Exceptional.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/ByteSwapper.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/Base64.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/Compiler/pushpack1.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/Compiler/poppack1.h"
    "/home/mischa/CLionProjects/untitled/vendor/assimp/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

