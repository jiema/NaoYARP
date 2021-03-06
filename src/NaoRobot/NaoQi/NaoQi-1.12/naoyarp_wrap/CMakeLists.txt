cmake_minimum_required(VERSION 2.8)

## Copyright (c) 2011, Aldebaran Robotics
## All rights reserved.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted provided that the following conditions are met:
##     * Redistributions of source code must retain the above copyright
##       notice, this list of conditions and the following disclaimer.
##     * Redistributions in binary form must reproduce the above copyright
##       notice, this list of conditions and the following disclaimer in the
##       documentation and/or other materials provided with the distribution.
##     * Neither the name of the Aldebaran Robotics nor the
##       names of its contributors may be used to endorse or promote products
##       derived from this software without specific prior written permission.
##
## THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
## ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
## WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
## DISCLAIMED. IN NO EVENT SHALL Aldebaran Robotics BE LIABLE FOR ANY
## DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
## (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
## LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
## ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
## (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
## SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
project(naoyarpw)

# You need this to find the QiBuild CMake framework
include("qibuild.cmake")

find_package(YARP REQUIRED)
include_directories(${YARP_INCLUDE_DIRS})

add_subdirectory(./NaoYARP/)
include_directories(./NaoYARP/src/)


# Create a executable named naoyarpw
# with the source file: main.cpp
qi_create_bin(naoyarpw "main.cpp")


option(NaoYARP_IS_REMOTE
    "module is compiled as a remote module (ON or OFF)"
    ON)


if(NaoYARP_IS_REMOTE)
    add_definitions( " -DNaoYARP_IS_REMOTE")
    qi_create_bin(naoyarpw "main.cpp" )
else()
    qi_create_lib(naoyarpw SHARED "main.cpp" )
endif()

target_link_libraries ( naoyarpw LibNaoQi_1_12 LibYarpDev)


qi_use_lib(naoyarpw ALCOMMON BOOST)


