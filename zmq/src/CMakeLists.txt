include_directories(${PROJECT_SOURCE_DIR} ${JASPER_EXTERNAL_INCLUDE})

file(GLOB src-files
    server.cpp
    client.cpp
  )

add_library(src-objs OBJECT ${src-files})
set_property(TARGET src-objs PROPERTY CXX_STANDARD 11)
add_dependencies(src-objs ${external_project_dependencies})

# server
add_executable(server server.cpp)
target_link_libraries(server jasper)
target_link_libraries(server ${JASPER_EXTERNAL_LIB})
set_property(TARGET server PROPERTY CXX_STANDARD 11)
add_dependencies(server ${external_project_dependencies})

# client
add_executable(client client.cpp)
target_link_libraries(client jasper)
target_link_libraries(client ${JASPER_EXTERNAL_LIB})
set_property(TARGET client PROPERTY CXX_STANDARD 11)
add_dependencies(client ${external_project_dependencies})