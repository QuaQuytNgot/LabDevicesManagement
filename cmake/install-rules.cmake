install(
    TARGETS LabDevicesManagement_exe
    RUNTIME COMPONENT LabDevicesManagement_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
