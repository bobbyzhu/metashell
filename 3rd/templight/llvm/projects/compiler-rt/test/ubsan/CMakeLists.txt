set(UBSAN_LIT_TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(UBSAN_TESTSUITES)
set(UBSAN_TEST_DEPS ${SANITIZER_COMMON_LIT_TEST_DEPS})

macro(add_ubsan_testsuite test_mode sanitizer arch)
  set(UBSAN_LIT_TEST_MODE "${test_mode}")
  set(CONFIG_NAME ${UBSAN_LIT_TEST_MODE}-${arch})
  configure_lit_site_cfg(
    ${CMAKE_CURRENT_SOURCE_DIR}/lit.site.cfg.in
    ${CMAKE_CURRENT_BINARY_DIR}/${CONFIG_NAME}/lit.site.cfg)
  list(APPEND UBSAN_TESTSUITES ${CMAKE_CURRENT_BINARY_DIR}/${CONFIG_NAME})
  if(NOT COMPILER_RT_STANDALONE_BUILD)
    list(APPEND UBSAN_TEST_DEPS ${sanitizer})
  endif()
endmacro()

foreach(arch ${UBSAN_SUPPORTED_ARCH})
  set(UBSAN_TEST_TARGET_ARCH ${arch})
  if(${arch} MATCHES "arm|aarch64")
    # This is only true if we're cross-compiling.
    set(UBSAN_TEST_TARGET_CFLAGS ${COMPILER_RT_TEST_COMPILER_CFLAGS})
  else()
    get_target_flags_for_arch(${arch} UBSAN_TEST_TARGET_CFLAGS)
    string(REPLACE ";" " " UBSAN_TEST_TARGET_CFLAGS "${UBSAN_TEST_TARGET_CFLAGS}")
  endif()
  add_ubsan_testsuite("Standalone" ubsan ${arch})

  if(COMPILER_RT_HAS_ASAN AND ";${ASAN_SUPPORTED_ARCH};" MATCHES ";${arch};")
    add_ubsan_testsuite("AddressSanitizer" asan ${arch})
  endif()
  if(COMPILER_RT_HAS_MSAN AND ";${MSAN_SUPPORTED_ARCH};" MATCHES ";${arch};")
    add_ubsan_testsuite("MemorySanitizer" msan ${arch})
  endif()
  if(COMPILER_RT_HAS_TSAN AND ";${TSAN_SUPPORTED_ARCH};" MATCHES ";${arch};")
    add_ubsan_testsuite("ThreadSanitizer" tsan ${arch})
  endif()
endforeach()

add_lit_testsuite(check-ubsan "Running UndefinedBehaviorSanitizer tests"
  ${UBSAN_TESTSUITES}
  DEPENDS ${UBSAN_TEST_DEPS})
set_target_properties(check-ubsan PROPERTIES FOLDER "UBSan tests")
