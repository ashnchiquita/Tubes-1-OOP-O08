cmake_minimum_required(VERSION 3.25)
project(Tubes-1-OOP-O08)

add_executable(Tubes-1-OOP-O08
    # main
    src/main.cpp

    # command
    src/command/command.cpp

    # ability command
    src/command/ability_command/ability_command.cpp
    src/command/ability_command/abilityless.cpp
    src/command/ability_command/quadruple.cpp
    src/command/ability_command/quarter.cpp
    src/command/ability_command/reroll.cpp
    src/command/ability_command/reverse_direction.cpp
    src/command/ability_command/swap_card.cpp
    src/command/ability_command/switch_card.cpp
    
    # basic command
    src/command/basic_command/basic_command.cpp
    src/command/basic_command/double.cpp
    src/command/basic_command/half.cpp
    src/command/basic_command/help.cpp
    src/command/basic_command/next.cpp
    
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
    src/valuables/ability_card.cpp
    )

set_target_properties(Tubes-1-OOP-O08
    PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR}/../bin)