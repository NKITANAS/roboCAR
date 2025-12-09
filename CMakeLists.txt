# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.2.0)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.2.0-a4)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# == DO NOT EDIT (VS Code extension requirement) ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.2.0)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.2.0-a4)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ==================================================

set(PICO_BOARD pico2_w CACHE STRING "Board type")

include(pico_sdk_import.cmake)

project(roboCAR C CXX ASM)

set(PICO_CXX_ENABLE_EXCEPTIONS 1)
set(PICO_CXX_ENABLE_RTTI 1)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Collect all .cpp files from src/cpp
file(GLOB_RECURSE ROBOCAR_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/src/cpp/*.cpp"
)

# Create executable
add_executable(roboCAR
    ${ROBOCAR_SOURCES}
)

pico_set_program_name(roboCAR "roboCAR")
pico_set_program_version(roboCAR "0.1")

# Enable or disable USB/UART stdio
pico_enable_stdio_uart(roboCAR 0)
pico_enable_stdio_usb(roboCAR 0)

# Libraries to link
target_link_libraries(roboCAR
    pico_stdlib
)

# Add include directory
target_include_directories(roboCAR PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/include
)

# Add any extra user libraries below
target_link_libraries(roboCAR
    # your additional libraries here
)

# Generate UF2, bin, and map files
pico_add_extra_outputs(roboCAR)
