cmake_minimum_required(VERSION 3.12)
project(virus)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

include_directories(/usr/lib/ ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)

add_library(util Math.cpp Math.h Random.cpp Random.h)

add_library(components Component.cpp Component.h SpriteComponent.cpp SpriteComponent.h CollisionComponent.cpp CollisionComponent.h)
target_link_libraries(components ${SDL2_LIBRARIES})

add_library(actor Actor.cpp Actor.h Player.cpp Player.h)
target_link_libraries(actor components ${SDL2_LIBRARIES})

add_library(animated_sprite AnimatedSprite.cpp AnimatedSprite.h)
target_link_libraries(animated_sprite components actor)

add_library(item Item.cpp Item.h)
target_link_libraries(item actor)

add_library(lootboxes Text.h LootBox.cpp LootBox.h NormalLootBox.cpp NormalLootBox.h PrestigeLootBox.cpp PrestigeLootBox.h UltraLootBox.cpp UltraLootBox.h)
target_link_libraries(lootboxes item actor components util animated_sprite ${SDL2_LIBRARIES})

add_executable(virus Main.cpp Game.cpp Game.h)
target_link_libraries(virus actor util lootboxes ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES})

