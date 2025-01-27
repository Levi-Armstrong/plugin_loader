find_gtest()

# Test plugin definition and explict template instantiation of plugin loader for test plugin class
add_library(${PROJECT_NAME}_plugin SHARED plugin.cpp)
target_link_libraries(${PROJECT_NAME}_plugin PUBLIC ${PROJECT_NAME})
target_cxx_version(${PROJECT_NAME}_plugin PUBLIC VERSION 17)
target_clang_tidy(${PROJECT_NAME}_plugin ENABLE ${ENABLE_CLANG_TIDY})

# Test Implementation Library
add_library(${PROJECT_NAME}_plugin_impl SHARED plugin_impl.cpp)
target_link_libraries(${PROJECT_NAME}_plugin_impl PUBLIC ${PROJECT_NAME}_plugin)
target_cxx_version(${PROJECT_NAME}_plugin_impl PUBLIC VERSION 17)
target_clang_tidy(${PROJECT_NAME}_plugin_impl ENABLE ${ENABLE_CLANG_TIDY})

# Unit test
add_executable(${PROJECT_NAME}_utest utest.cpp)
target_link_libraries(${PROJECT_NAME}_utest PRIVATE ${PROJECT_NAME}_plugin GTest::GTest GTest::Main)
add_gtest_discover_tests(${PROJECT_NAME}_utest)
add_dependencies(run_tests ${PROJECT_NAME}_utest)
target_compile_definitions(${PROJECT_NAME}_utest PRIVATE PLUGIN_DIR="${CMAKE_INSTALL_PREFIX}/lib"
                                                         PLUGINS="${PROJECT_NAME}_plugin_impl")

# Install the targets
install(
  TARGETS ${PROJECT_NAME}_plugin_impl ${PROJECT_NAME}_plugin ${PROJECT_NAME}_utest
  EXPORT ${PROJECT_NAME}-targets
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)
