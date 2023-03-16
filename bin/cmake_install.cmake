# Install script for directory: /Users/owner/Documents/sem4/stima/tucil2/Tubes-1-OOP-O08

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
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

<<<<<<< HEAD
# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

=======
>>>>>>> 1a1f127a64c077fdd6413aab735191021526bdb6
# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
<<<<<<< HEAD
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
=======
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
>>>>>>> 1a1f127a64c077fdd6413aab735191021526bdb6
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD:cmake_install.cmake
<<<<<<< HEAD
file(WRITE "/home/rma1403/Documents/Programming/kuliah/Tubes-1-OOP-O08/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "/Users/alishalistya/VSCode/Tubes-1-OOP-O08/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> 1a1f127a64c077fdd6413aab735191021526bdb6
=======
file(WRITE "/Users/owner/Documents/sem4/stima/tucil2/Tubes-1-OOP-O08/bin/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> 9e7df66541bbf01add16067f9306c9f07846f6b8:bin/cmake_install.cmake
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
