project(myApp LANGUAGES CXX)

find_package(Matlab 9.6 REQUIRED)

# find_package(OpenMP 2.0 REQUIRED)

# define sources for myApp
set(SRCS_TO_BUILD
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/App.cpp
    ${PROJECT_SOURCE_DIR}/src/Demo.cpp
    ${PROJECT_SOURCE_DIR}/src/image_helper.cpp
    ${CMAKE_SOURCE_DIR}/lib/imgui/backends/imgui_impl_glfw.cpp # imgui backend
    ${CMAKE_SOURCE_DIR}/lib/imgui/backends/imgui_impl_opengl3.cpp # imgui backend
)

add_compile_definitions(IMGUI_USER_CONFIG="my_imgui_config.h")

# Create the executable
add_executable(${PROJECT_NAME}
    ${SRCS_TO_BUILD}
)

# include dirs
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
    PUBLIC ${CMAKE_SOURCE_DIR}/lib/eigen/
    PUBLIC ${CMAKE_SOURCE_DIR}/lib/imgui
    PUBLIC ${CMAKE_SOURCE_DIR}/lib/imgui/backends
    PUBLIC ${CMAKE_SOURCE_DIR}/lib/glew/include
    PUBLIC ${CMAKE_SOURCE_DIR}/lib/stb
    PUBLIC ${GLFW_INCLUDE_DIR}
    PUBLIC ${Matlab_INCLUDE_DIRS}
)

# target_link_directories(${PROJECT_NAME}
# PRIVATE ${CMAKE_SOURCE_DIR}/lib/glfw/src
# )
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    glfw libglew_static
    IMGUI IMPLOT
)

# COPY RES
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources/
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources/)

# FILE(COPY ${CMAKE_SOURCE_DIR}/resources/Roboto-Medium.ttf DESTINATION "${CMAKE_BINARY_DIR}")

# we don't want to copy if we're building in the source dir
# list of files for which we add a copy rule
# set(data_SHADOW Roboto-Medium.ttf)

# foreach(item IN LISTS data_SHADOW)
# message(STATUS ${item})
# message(STATUS ${CMAKE_SOURCE_DIR}/resources/${item})
# message(STATUS ${CMAKE_CURRENT_BINARY_DIR}/${item})
# add_custom_command(

# OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${item}"
# COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/resources/${item}" "${CMAKE_CURRENT_BINARY_DIR}/${item}"
# DEPENDS "${CMAKE_SOURCE_DIR}/resources/${item}"
# )
# endforeach()

# # files are only copied if a target depends on them
# add_custom_target(data-target ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/Roboto-Medium.ttf")

# https://www.reddit.com/r/cmake/comments/gmewhu/copy_one_file_in_src_directory_to_build_directory/
# # Copy <filename> to build directory
# set(copy_source_dir "${CMAKE_SOURCE_DIR}/src/<path>")
# set(copy_dest_dir "${CMAKE_BINARY_DIR}/Build/<path>/$<CONFIG>")
# set(copy_file_name "<filename>")
# add_custom_command(
# TARGET ${PROJECT_NAME} POST_BUILD
# COMMAND ${CMAKE_COMMAND} -E make_directory ${copy_dest_dir}
# )
# add_custom_command(
# TARGET ${PROJECT_NAME} POST_BUILD
# COMMAND ${CMAKE_COMMAND} -E copy "${copy_source_dir}/${copy_file_name}" "${copy_dest_dir}/${copy_file_name}"
# COMMENT "Copying ${copy_file_name} to build directory"
# )