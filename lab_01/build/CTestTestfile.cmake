# CMake generated Testfile for 
# Source directory: /home/tim/Zaytsev_Tim_OOP_Labs/lab_01
# Build directory: /home/tim/Zaytsev_Tim_OOP_Labs/lab_01/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyProjectTests "/home/tim/Zaytsev_Tim_OOP_Labs/lab_01/build/tests")
set_tests_properties(MyProjectTests PROPERTIES  _BACKTRACE_TRIPLES "/home/tim/Zaytsev_Tim_OOP_Labs/lab_01/CMakeLists.txt;28;add_test;/home/tim/Zaytsev_Tim_OOP_Labs/lab_01/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
