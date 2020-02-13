/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:36:42 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/13 12:10:55 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <thread>

#include <unistd.h>

#include <Python.h>
#include <numpy/arrayobject.h>
/* #include "matplotlibcpp.h" */

#define DATA_FILE "files/data.csv"
#define THETA_FILE "files/thetaFile.csv"
#define DELIMETER ','
#define LEARNING_RATE 0.02
/* #define CYCLES 5 */
#define CYCLES 6000

using namespace std;
/* namespace plt = matplotlibcpp; */
