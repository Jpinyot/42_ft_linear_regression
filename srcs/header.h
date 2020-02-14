/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:36:42 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/14 11:55:40 by jpinyot          ###   ########.fr       */
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

#define DATA_FILE "files/data.csv"
#define THETA_FILE "files/thetaFile.csv"
#define DELIMETER ','
#define LEARNING_RATE 0.02
/* #define CYCLES 5 */
#define CYCLES 6000

using namespace std;

/* enum Flags */
/* { */
/* 	plotThetaError =		001, */
/* 	plotPrediction =		0010, */
/* 	plotPredictionAndData =	00100 */
/* }; */
