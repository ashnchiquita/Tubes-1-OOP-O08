cmake_minimum_required(VERSION 3.25)
project(Tubes-1-OOP-O08)

add_executable(Tubes-1-OOP-O08
    src/main.cpp
    src/command/ability_command.cpp
    src/command/basic_command.cpp
    src/command/command.cpp
    src/game/game.cpp
    src/input_handler/input_handler.cpp
    src/input_handler/file_handler.cpp
    src/inventory_holder/deck.cpp
    src/inventory_holder/player.cpp
    src/inventory_holder/table_card.cpp
    src/playerslist/playerslist.cpp
    src/valuables/card.cpp
    src/valuables/combo.cpp
    )

set_target_properties(Tubes-1-OOP-O08
    PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR}/../bin)