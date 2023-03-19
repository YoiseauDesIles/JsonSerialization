cmake_minimum_required(VERSION 3.0.0)
project(JsonSerialization VERSION 0.1.0)

set(SRCS
main.cpp
Sources/JSONBase.cpp
Sources/Product.cpp
Sources/Product2.cpp
)

set(HEADERS
Includes/JSONBase.h
Includes/Product.h
Includes/Product2.h
)

add_executable(JsonSerialization ${SRCS} ${HEADERS})




