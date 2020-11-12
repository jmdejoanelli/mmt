cmake_minimum_required(VERSION 3.15)
project(media_management_tool)

add_executable(mmt)

target_compile_features(mmt
PUBLIC
	cxx_std_17
)

target_sources(mmt
PUBLIC
	src/Magic.cpp
	src/main.cpp
)

target_include_directories(mmt
PUBLIC
	include
)

target_link_libraries(mmt
PUBLIC
	magic
)
