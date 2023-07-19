project(myApp LANGUAGES CXX)

# define sources for myApp
set(SRCS_TO_BUILD
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/App.cpp
    ${PROJECT_SOURCE_DIR}/src/Demo.cpp
    ${PROJECT_SOURCE_DIR}/src/image_helper.cpp
    ${VENDOR_PATH}/imgui/backends/imgui_impl_glfw.cpp # imgui backend
    ${VENDOR_PATH}/imgui/backends/imgui_impl_opengl3.cpp # imgui backend
)
message("HALLO: ${MYIMGUI_CONFIG}")

# Create the executable
add_executable(${PROJECT_NAME}
    ${SRCS_TO_BUILD}
)
target_compile_definitions(${PROJECT_NAME} PUBLIC IMGUI_USER_CONFIG="${MYIMGUI_CONFIG}")

# include dirs
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
    PUBLIC ${VENDOR_PATH}/imgui
    PUBLIC ${VENDOR_PATH}/imgui/backends
    PUBLIC ${VENDOR_PATH}/glew/include
    PUBLIC ${VENDOR_PATH}/stb
    PUBLIC ${GLFW_INCLUDE_DIR}
)

# target_link_directories(${PROJECT_NAME}
# PRIVATE ${CMAKE_SOURCE_DIR}/lib/glfw/src
# )
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    glfw
    libglew_static
    IMGUI
    IMPLOT
)

# IMPLOT

# COPY RES
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources/
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources/)

# FILE(COPY ${CMAKE_SOURCE_DIR}/resources/Roboto-Medium.ttf DESTINATION "${CMAKE_BINARY_DIR}")
