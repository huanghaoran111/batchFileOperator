add_executable(TestCryptFile 
    Test_crypt_file.cpp 
    ${PROJECT_SOURCE_DIR}/src/XCrypt/xcrypt.cpp)
target_include_directories(TestCryptFile PRIVATE ${OPENSSL_INCLUDE_DIR} ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(TestCryptFile ${OPENSSL_LIBRARIES})

add_executable(TestXreadFile 
    Test_read_task.cpp 
    ${PROJECT_SOURCE_DIR}/src/XReadTask/xread_task.cpp
    ${PROJECT_SOURCE_DIR}/src/XIOStream/xiostream.cpp
    ${PROJECT_SOURCE_DIR}/src/XData/xdata.cpp)
target_include_directories(TestXreadFile PRIVATE ${PROJECT_SOURCE_DIR}/src)

add_executable(TestCreatePool 
    Test_create_pool.cpp 
    ${PROJECT_SOURCE_DIR}/src/XReadTask/xread_task.cpp
    ${PROJECT_SOURCE_DIR}/src/XIOStream/xiostream.cpp
    ${PROJECT_SOURCE_DIR}/src/XData/xdata.cpp
)
target_include_directories(TestCreatePool PRIVATE ${PROJECT_SOURCE_DIR}/src)

add_executable(TestChainRes
    Test_chain_res.cpp
    ${PROJECT_SOURCE_DIR}/src/XReadTask/xread_task.cpp
    ${PROJECT_SOURCE_DIR}/src/XIOStream/xiostream.cpp
    ${PROJECT_SOURCE_DIR}/src/XData/xdata.cpp
    ${PROJECT_SOURCE_DIR}/src/XCrypt/xcrypt.cpp
    ${PROJECT_SOURCE_DIR}/src/XCryptTask/xcrypt_task.cpp
)
target_include_directories(TestChainRes PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(TestChainRes ${OPENSSL_LIBRARIES})

add_executable(TestRunTask1
    Test_run_task1.cpp
    ${PROJECT_SOURCE_DIR}/src/XReadTask/xread_task.cpp
    ${PROJECT_SOURCE_DIR}/src/XIOStream/xiostream.cpp
    ${PROJECT_SOURCE_DIR}/src/XData/xdata.cpp
    ${PROJECT_SOURCE_DIR}/src/XCrypt/xcrypt.cpp
    ${PROJECT_SOURCE_DIR}/src/XCryptTask/xcrypt_task.cpp
)
target_include_directories(TestRunTask1 PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(TestRunTask1 ${OPENSSL_LIBRARIES})

add_executable(TestWriteTask
    Test_write_task.cpp
    ${PROJECT_SOURCE_DIR}/src/XReadTask/xread_task.cpp
    ${PROJECT_SOURCE_DIR}/src/XIOStream/xiostream.cpp
    ${PROJECT_SOURCE_DIR}/src/XData/xdata.cpp
    ${PROJECT_SOURCE_DIR}/src/XCrypt/xcrypt.cpp
    ${PROJECT_SOURCE_DIR}/src/XCryptTask/xcrypt_task.cpp
    ${PROJECT_SOURCE_DIR}/src/XWriteTask/xwrite_task.cpp
)
target_include_directories(TestWriteTask PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(TestWriteTask ${OPENSSL_LIBRARIES})

add_executable(TestRunDecrypt
    Test_run_decrypt.cpp
    ${PROJECT_SOURCE_DIR}/src/XReadTask/xread_task.cpp
    ${PROJECT_SOURCE_DIR}/src/XIOStream/xiostream.cpp
    ${PROJECT_SOURCE_DIR}/src/XData/xdata.cpp
    ${PROJECT_SOURCE_DIR}/src/XCrypt/xcrypt.cpp
    ${PROJECT_SOURCE_DIR}/src/XCryptTask/xcrypt_task.cpp
    ${PROJECT_SOURCE_DIR}/src/XWriteTask/xwrite_task.cpp
)
target_include_directories(TestRunDecrypt PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(TestRunDecrypt ${OPENSSL_LIBRARIES})

add_executable(TestRunFilecrypt
    Test_run_filecrypt.cpp
    ${PROJECT_SOURCE_DIR}/src/XReadTask/xread_task.cpp
    ${PROJECT_SOURCE_DIR}/src/XIOStream/xiostream.cpp
    ${PROJECT_SOURCE_DIR}/src/XData/xdata.cpp
    ${PROJECT_SOURCE_DIR}/src/XCrypt/xcrypt.cpp
    ${PROJECT_SOURCE_DIR}/src/XCryptTask/xcrypt_task.cpp
    ${PROJECT_SOURCE_DIR}/src/XWriteTask/xwrite_task.cpp
    ${PROJECT_SOURCE_DIR}/src/XFileCrypt/xfile_crypt.cpp
)
target_include_directories(TestRunFilecrypt PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(TestRunFilecrypt ${OPENSSL_LIBRARIES})

