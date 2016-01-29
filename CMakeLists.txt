cmake_minimum_required(VERSION 2.8)
project(sslchain)

find_package(OpenSSL REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lssl -lcrypto -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")

#set(SOURCE_FILES *.cpp *.h )
file(GLOB SOURCE_FILES
        #"*.h"
        "*.cpp"
)

file(GLOB CRYPTO_DIR
        " ${CMAKE_SOURCE_DIR}/crypto/"
)

file(GLOB PRIMITIVE_DIR
        " ${CMAKE_SOURCE_DIR}/primitives/"
)

include_directories(${CRYPTO_DIR} ${PRIMITIVE_DIR} ${OPENSSL_INCLUDE_DIR})

file(GLOB CRYPTO_SRC
        ${CMAKE_SOURCE_DIR}/crypto/*.cpp
)

file(GLOB PRIMITIVE_SRC
        ${CMAKE_SOURCE_DIR}/primitives/*.cpp
)

add_executable( SSLChain ${CRYPTO_SRC} ${SOURCE_FILES} ${PRIMITIVE_SRC} )

target_link_libraries(SSLChain ${OPENSSL_LIBRARES})
target_link_libraries(SSLChain ${OPENSSL_SSL_LIBRARY})
target_link_libraries(SSLChain ${OPENSSL_CRYPTO_LIBRARY})
