# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\byteArr_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\byteArr_autogen.dir\\ParseCache.txt"
  "byteArr_autogen"
  )
endif()
