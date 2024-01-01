# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\taller_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\taller_autogen.dir\\ParseCache.txt"
  "taller_autogen"
  )
endif()
