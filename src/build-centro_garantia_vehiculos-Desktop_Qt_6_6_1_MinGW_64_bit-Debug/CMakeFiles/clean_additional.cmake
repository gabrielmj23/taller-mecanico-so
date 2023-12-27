# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\centro_garantia_vehiculos_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\centro_garantia_vehiculos_autogen.dir\\ParseCache.txt"
  "centro_garantia_vehiculos_autogen"
  )
endif()
