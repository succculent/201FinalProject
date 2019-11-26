cmake_minimum_required(VERSION 3.10)

#set the cpp version
set(CMAKE_CC_FLAGS "${CMAKE_CC_FLAGS} -std=c++14")

# set the project name
project(BTC_Miner)

# add CPR subdirectory
add_subdirectory(cpr)

# add the executable
add_executable(
	BTC_Miner 
	temp-miner.cpp

)
# link CPR
include_directories(${CPR_INCLUDE_DIRS})
target_link_libraries(BTC_Miner ${CPR_LIBRARIES})
