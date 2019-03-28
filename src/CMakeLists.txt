cmake_minimum_required(VERSION 2.8)

PROJECT(vtkOBJViewer)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(vtkOBJViewer MACOSX_BUNDLE vtkOBJViewer.cxx helperFunctions.cxx vtkOBJWriter.cxx)

if(VTK_LIBRARIES)
  target_link_libraries(vtkOBJViewer ${VTK_LIBRARIES})
else()
  target_link_libraries(vtkOBJViewer vtkHybrid vtkWidgets)
endif()
