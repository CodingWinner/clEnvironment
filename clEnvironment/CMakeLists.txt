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
target_include_directories(clEnvironment PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_include_directories(clEnvironment PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

install(TARGETS clEnvironment EXPORT clEnvironmentTargets DESTINATION install/lib)
install(TARGETS clEnvironment EXPORT clEnvironmentTargets DESTINATION install/lib)
install(DIRECTORY include/ DESTINATION install/include)

install(EXPORT clEnvironmentTargets
    FILE clEnvironment.cmake
    NAMESPACE clEnvironment::
    DESTINATION install/lib/cmake/clEnvironment
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/clEnvironmentConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/../cmake/clEnvironmentConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/clEnvironmentConfig.cmake"
    INSTALL_DESTINATION install/lib/cmake/clEnvironment
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/clEnvironmentConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/clEnvironmentConfigVersion.cmake"
    DESTINATION install/lib/cmake/clEnvironment
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET clEnvironment PROPERTY CXX_STANDARD 20)
endif()