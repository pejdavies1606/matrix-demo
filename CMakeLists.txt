cmake_minimum_required(VERSION 3.13)
set(project_name matrix)
project(${project_name})
set(inc
	"include/matrix.hpp"
)
set(src
	"src/main.cpp"
)
add_executable(${project_name}
	${inc}
	${src}
)
target_include_directories(${project_name}
	PUBLIC "include"
)
