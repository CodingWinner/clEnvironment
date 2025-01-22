# Find required packages

find_package(OpenCL CONFIG REQUIRED)

# Macro options
option(CREATE_SHARED_LIB "Create a shared or static library (off = static, on = shared)" OFF)

# Create lib
if (CREATE_SHARED_LIB)
	add_library(clEnvironment SHARED clEnvironment.cpp)
else()
	add_library(clEnvironment STATIC clEnvironment.cpp)
endif()

target_link_libraries(clEnvironment PUBLIC OpenCL::OpenCL)
target_include_directories(clEnvironment PUBLIC ${CMAKE_SOURCE_DIR})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET clEnvironment PROPERTY CXX_STANDARD 20)
endif()