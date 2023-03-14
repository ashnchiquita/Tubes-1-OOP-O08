cmake_minimum_required(VERSION 3.25)
project(Tubes-1-OOP-O08)

add_executable(Tubes-1-OOP-O08
    # main
    src/main.cpp

    # command
    src/command/ability_command.cpp
    src/command/basic_command.cpp
    src/command/command.cpp

    # exception
    # -

    # game
    src/game/game.cpp

    # input_handler
    src/input_handler/file_handler.cpp

    # inventory holder
    src/inventory_holder/deck.cpp
    src/inventory_holder/player.cpp
    src/inventory_holder/table_card.cpp

    # playerslist
    src/playerslist/playerslist.cpp

    # valuables
    src/valuables/card.cpp
    src/valuables/combo.cpp
    )

set_target_properties(Tubes-1-OOP-O08
    PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR}/../bin)