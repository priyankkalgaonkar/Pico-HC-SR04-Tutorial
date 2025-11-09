cmake_minimum_required(VERSION 3.13)

# Initialize the Pico SDK
include(pico_sdk_import.cmake)

project(my_hcsr04_project)

# Initialize the SDK
pico_sdk_init()

# Create the executable
add_executable(hcsr04_demo
    hcsr04_demo.c
)

# Link against the pico_stdlib which includes core functionality
target_link_libraries(hcsr04_demo pico_stdlib)

# Enable USB output, so we can use printf
pico_enable_stdio_usb(hcsr04_demo 1)
pico_enable_stdio_uart(hcsr04_demo 0)

# Create the Pico binary file
pico_add_extra_outputs(hcsr04_demo)