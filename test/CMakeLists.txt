# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(LabDevicesManagementTests LANGUAGES CXX)

# ---- Tests ----

add_executable(LabDevicesManagement_test source/LabDevicesManagement_test.cpp)
target_link_libraries(LabDevicesManagement_test PRIVATE LabDevicesManagement_lib)
target_compile_features(LabDevicesManagement_test PRIVATE cxx_std_17)

add_test(NAME LabDevicesManagement_test COMMAND LabDevicesManagement_test)

# ---- End-of-file commands ----

add_folders(Test)
