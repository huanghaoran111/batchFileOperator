add_executable(cryptFile)
target_sources(cryptFile PRIVATE cryptFile.cpp)
target_link_libraries(cryptFile PRIVATE CryptFileLib)
