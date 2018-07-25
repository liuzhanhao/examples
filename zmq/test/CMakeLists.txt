include_directories(${PROJECT_SOURCE_DIR} ${JASPER_EXTERNAL_INCLUDE})

add_library(jasper STATIC
  $<TARGET_OBJECTS:src-objs>
  )

# Unit Test
file(GLOB_RECURSE UNITTEST_FILES ${PROJECT_SOURCE_DIR}/*_test.cpp) 
include_directories(${GTEST_INCLUDE})
add_executable(UnitTest ${UNITTEST_FILES} test_main.cpp)
add_dependencies(UnitTest gtest)
target_link_libraries(UnitTest jasper)
target_link_libraries(UnitTest ${JASPER_EXTERNAL_LIB})
target_link_libraries(UnitTest ${GTEST_LIBRARIES})
target_link_libraries(UnitTest ${GMOCK_LIBRARIES})
set_property(TARGET UnitTest PROPERTY CXX_STANDARD 11)
add_dependencies(UnitTest ${external_project_dependencies})
