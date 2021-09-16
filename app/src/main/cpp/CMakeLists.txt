cmake_minimum_required(VERSION 3.10.2)

project("rpath")

find_library(log-lib log)

add_library(alpha SHARED alpha.cpp)
target_link_libraries(alpha PRIVATE ${log-lib})

add_library(beta SHARED beta.cpp)
target_link_libraries(beta PRIVATE ${log-lib})

# add_library(gamma SHARED gamma.cpp)
# target_link_libraries(gamma PRIVATE ${log-lib})

set(LIBS_ROOT ${PROJECT_SOURCE_DIR}/../../../libs)
set(LIBS_DIR "${LIBS_ROOT}/${ANDROID_ABI}")

add_library(gamma SHARED IMPORTED)
set_target_properties(gamma PROPERTIES IMPORTED_LOCATION ${LIBS_DIR}/libgamma.so)

target_link_libraries(beta PRIVATE gamma)
target_link_libraries(alpha PRIVATE beta)
