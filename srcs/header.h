/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:36:42 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/19 09:08:10 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <thread>
#include <cmath>

#include <unistd.h>

#define DATA_FILE "files/data.csv"
#define THETA_FILE "files/thetaFile.csv"
#define DELIMETER ','
#define LEARNING_RATE 0.02
#define CYCLES 6000
#define NORM_PLOT 0.2

using namespace std;

/* enum Flags */
/* { */
/* 	plotThetaError =		001, */
/* 	plotPrediction =		0010, */
/* 	plotPredictionAndData =	00100 */
/* }; */

/* enum ErrorEstimatePrice */
/* { */
/* 	missingThetaFile */
/* }; */
