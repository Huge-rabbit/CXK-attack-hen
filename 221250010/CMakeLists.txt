cmake_minimum_required(VERSION 3.24)

project(CXK_ATTACK_HEN)

add_executable(CXK game.c player.c player.h resource.c resource.h mainmenu.c mainmenu.h)

target_link_libraries(CXK mingw32)
target_link_libraries(CXK SDL2main)
target_link_libraries(CXK SDL2)
target_link_libraries(CXK SDL2_image)
target_link_libraries(CXK SDL2_ttf)
