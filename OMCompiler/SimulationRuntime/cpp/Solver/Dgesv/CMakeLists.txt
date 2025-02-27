cmake_minimum_required(VERSION 2.8.9)

project(${DgesvName})

IF(DGESV_FOUND)
  MESSAGE(STATUS "DGESV enabled")
  include_directories (${DGESV_INCLUDE_DIR})
  add_library(${DgesvName}_static STATIC ${DGESV_SRCS})
  install(TARGETS ${DgesvName}_static DESTINATION ${LIBINSTALLEXT})
  install(FILES ${DGESV_HEADERS} DESTINATION include/omc/cpp/Solver/Dgesv)
  GET_TARGET_PROPERTY(libDgesvLocation ${DgesvName}_static LOCATION)
  GET_FILENAME_COMPONENT(libDgesvExt ${libDgesvLocation} EXT CACHE)

  add_library(${DgesvSolverName} DgesvSolver.cpp DgesvSolverSettings.cpp FactoryExport.cpp)

  if(NOT BUILD_SHARED_LIBS)
    set_target_properties(${DgesvSolverName} PROPERTIES COMPILE_DEFINITIONS "RUNTIME_STATIC_LINKING")
  endif(NOT BUILD_SHARED_LIBS)

  target_link_libraries(${DgesvSolverName}  ${SolverName} ${ExtensionUtilitiesName} ${Boost_LIBRARIES} ${LAPACK_LIBRARIES}  ${ModelicaName})
  add_precompiled_header(${DgesvSolverName} Core/Modelica.h)

  install(FILES $<TARGET_PDB_FILE:${DgesvSolverName}> DESTINATION ${LIBINSTALLEXT} OPTIONAL)

  install(TARGETS ${DgesvSolverName} DESTINATION ${LIBINSTALLEXT})
  install(FILES
    ${CMAKE_SOURCE_DIR}/Solver/Dgesv/DgesvSolver.h
    ${CMAKE_SOURCE_DIR}/Solver/Dgesv/DgesvSolverSettings.h
    ${CMAKE_SOURCE_DIR}/Solver/Dgesv/FactoryExport.h
    DESTINATION include/omc/cpp/Solver/Dgesv)

ELSE()
  MESSAGE(STATUS "DGESV disabled")
ENDIF(DGESV_FOUND)

