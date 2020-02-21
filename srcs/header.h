/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:36:42 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/21 11:44:57 by jpinyot          ###   ########.fr       */
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

enum Flags
{
	noFlags = 0,
	plotCost = 1,
	plotData = 2,
	plotPrediction = 4,
	printAccuracy = 8,
	/* interactiveMode = 5 */
};

inline Flags operator|(Flags a, Flags b)
{
	return static_cast<Flags>(static_cast<int>(a) | static_cast<int>(b));
}
#endif
