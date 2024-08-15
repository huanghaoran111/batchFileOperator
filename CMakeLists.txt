cmake_minimum_required(VERSION 3.20)

project(BatchFileOperator)

find_package(OpenSSL REQUIRED)

# 输出调试信息
if(NOT OpenSSL_FOUND)
    message(FATAL_ERROR "OpenSSL not found")
else()
    message(STATUS "OpenSSL include dirs: ${OPENSSL_INCLUDE_DIR}")
    message(STATUS "OpenSSL libraries: ${OPENSSL_LIBRARIES}")
endif()

add_subdirectory(tests)

set(SRC_
    ${CMAKE_CURRENT_SOURCE_DIR}/src/XReadTask/xread_task.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/XIOStream/xiostream.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/XData/xdata.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/XCrypt/xcrypt.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/XCryptTask/xcrypt_task.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/XWriteTask/xwrite_task.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/XFileCrypt/xfile_crypt.cpp
)

add_library(CryptFileLib STATIC)
target_sources(CryptFileLib PRIVATE ${SRC_})
target_include_directories(CryptFileLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(CryptFileLib PRIVATE ${OPENSSL_LIBRARIES})

add_subdirectory(tool)