/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:36:42 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/20 11:48:42 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HEADERH_
#define _HEADERH_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <thread>
#include <cmath>
#include <stdlib.h>

#include <unistd.h>

#define DATA_FILE "files/data.csv"
#define THETA_FILE "files/thetaFile.csv"
#define DELIMETER ','
#define LEARNING_RATE 0.02
#define CYCLES 4000
#define NORM_PLOT 0.2

using namespace std;

enum flags
{
	plotCost = 1,
	plotPrediction = 2,
	printAccuracy = 4,
	interactiveMode = 5
};
#endif
