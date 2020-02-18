# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 12:28:11 by jpinyot           #+#    #+#              #
#    Updated: 2020/02/18 11:25:57 by jpinyot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 11)

# set the project name
project(ft_linear_regression)
project(linear_regression)
project(estimate_price)

# add the executable
	# ft_linear_regressin
add_executable(	ft_linear_regression
				srcs/main.cpp
				srcs/linearRegression.cpp
				srcs/estimatePrice.cpp
				srcs/plot.cpp)
set(HEADER_FILES	ft_linear_regression
					srcs/linearRegression.h
 					srcs/estimatePrice.h
 					srcs/header.h
					srcs/plot.h)

	# linear_regression
add_executable(	linear_regression
				srcs/mainLinReg.cpp
				srcs/linearRegression.cpp)
set(HEADER_FILES	linear_regression
					srcs/linearRegression.h
 					srcs/header.h)

	# estimate_price
add_executable(	estimate_price
				srcs/mainEstPrice.cpp
				srcs/estimatePrice.cpp)
set(HEADER_FILES	estimate_price
 					srcs/estimatePrice.h
 					srcs/header.h)


# dependencies for Python.h, used for ploting
find_package(Python2 COMPONENTS Development NumPy)
target_include_directories(ft_linear_regression PRIVATE ${Python2_INCLUDE_DIRS} ${Python2_NumPy_INCLUDE_DIRS})
target_link_libraries(ft_linear_regression Python2::Python Python2::NumPy)
