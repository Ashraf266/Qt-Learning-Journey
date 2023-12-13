# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Qstr_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Qstr_autogen.dir\\ParseCache.txt"
  "Qstr_autogen"
  )
endif()
