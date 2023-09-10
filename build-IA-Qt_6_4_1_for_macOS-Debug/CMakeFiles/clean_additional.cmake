# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appIA_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appIA_autogen.dir/ParseCache.txt"
  "appIA_autogen"
  )
endif()
