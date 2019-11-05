cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

add_service_files(
  FILES
  AddTwoInts.srv
)

generate_messages(DEPENDENCIES std_msgs)

catkin_package(
  CATKIN_DEPENDS
    roscpp
    std_msgs
    message_generation
)

include_directories(include
  ${catkin_INCLUDE_DIRS}
)

add_executable(talker src/talker.cpp)
add_dependencies(talker ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(talker ${catkin_LIBRARIES})

add_executable(listener src/listener.cpp)
add_dependencies(listener${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(listener${catkin_LIBRARIES})

add_executable(server src/server.cpp)
target_link_libraries(server${catkin_LIBRARIES})
add_dependencies(server beginner_tutorials_gencpp)

add_executable(client src/client.cpp)
target_link_libraries(client${catkin_LIBRARIES})
add_dependencies(clienttest beginner_tutorials_gencpp)
