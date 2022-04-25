# Recurse into subdirectories.
PROJECT(SPLDoc)

FIND_PACKAGE(Doxygen REQUIRED)
IF(NOT DOXYGEN_FOUND)
  MESSAGE(STATUS "Doxygen not found! Can't built the documentation!")  
ENDIF(NOT DOXYGEN_FOUND)

# N.B. Both the following custom rules assume the doc directory exists
# at make time, and the following install(DIRECTORY... must have doc exist
# at cmake time.  Therefore, create the doc directory at CMake time.
# (Linux experimentation indicates this is a no-op if the empty or
# non-empty directory already exists.)
file(MAKE_DIRECTORY ${SPLDoc_SOURCE_DIR}/html)

ADD_CUSTOM_COMMAND(
  OUTPUT ${SPLDoc_SOURCE_DIR}/html/index.html
  COMMAND ${DOXYGEN_EXECUTABLE} ${SPLDoc_SOURCE_DIR}/Doxyfile.user
  DEPENDS ${SPLDoc_SOURCE_DIR}/Doxyfile.user
  WORKING_DIRECTORY ${SPLDoc_SOURCE_DIR}
)

ADD_CUSTOM_TARGET(
  Documentation ALL
  DEPENDS
  ${SPLDoc_SOURCE_DIR}/html/index.html
  WORKING_DIRECTORY ${SPLDoc_SOURCE_DIR}
)

#INSTALL(DIRECTORY ${SPLDoc_SOURCE_DIR}/html DESTINATION ${SPL_INSTALL_DIR_DOC})
#INSTALL(DIRECTORY ${SPLDoc_SOURCE_DIR}/papers DESTINATION ${SPL_INSTALL_DIR_DOC})
#INSTALL(FILES ${SPLDoc_SOURCE_DIR}/index.html DESTINATION ${SPL_INSTALL_DIR_DOC})
