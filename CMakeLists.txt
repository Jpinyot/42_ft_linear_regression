# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 12:28:11 by jpinyot           #+#    #+#              #
#    Updated: 2020/02/15 10:45:12 by jpinyot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 11)

# set the project name
project(ft_linear_regression)

# add the executable
add_executable(	ft_linear_regression
				srcs/mainLinReg.cpp
				srcs/linearRegression.cpp
				srcs/estimatePrice.cpp
				srcs/plot.cpp)

# add ethe header files
set(HEADER_FILES	srcs/linearRegression.h
 					srcs/estimatePrice.h
 					srcs/header.h
					srcs/plot.h)
	 				# srcs/matplotlibcpp.h)

# dependencies for Python.h, used for ploting
find_package(Python2 COMPONENTS Development NumPy)
target_include_directories(ft_linear_regression PRIVATE ${Python2_INCLUDE_DIRS} ${Python2_NumPy_INCLUDE_DIRS})
target_link_libraries(ft_linear_regression Python2::Python Python2::NumPy)
