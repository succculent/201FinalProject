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
	test-miner.cpp

)
# link CPR
target_link_libraries(BTC_Miner ${CPR_LIBRARIES})
target_include_directories(BTC_Miner ${CPR_INCLUDE_DIRS})
