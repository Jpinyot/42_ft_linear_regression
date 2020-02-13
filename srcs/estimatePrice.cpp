/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimatePrice.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:30:47 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/13 12:10:59 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "estimatePrice.h"

void	EstimatePrice::getData()
{
	ifstream file(THETA_FILE);		//create errors
	
	string line = "";

	if (getline(file, line)){
		setTheta(line);
	}
	if (getline(file, line)){
		setMinMaxMile(line);
	}
	file.close();
}

void	EstimatePrice::setTheta(const string& line)
{
	int	delimeterPos = 0;
	if ((delimeterPos = line.find(DELIMETER)))			//DELIMETER
	{
		string theta0String = line.substr(0, delimeterPos); 
		string theta1String = line.substr(delimeterPos + 1, line.size());
		theta0_ = stod(theta0String);
		theta1_ = stod(theta1String);
	}
}

void	EstimatePrice::setMinMaxMile(const string& line)
{
	int	delimeterPos = 0;
	if ((delimeterPos = line.find(DELIMETER)))			//DELIMETER
	{
		string maxMile = line.substr(0, delimeterPos); 
		string minMile = line.substr(delimeterPos + 1, line.size());
		maxMile_ = stoi(maxMile);
		minMile_ = stoi(minMile);
	}
}

double	EstimatePrice::normalizeMile(const int& mileage)
{
	double normMile = (mileage - minMile_) / (maxMile_ - minMile_);
	return normMile;
}

double	EstimatePrice::predictPrice()			//WHAT WHEN NO MILEAGE??
{
	double normMile = normalizeMile(mileage_);
	estimatePrice_ = theta0_ + (theta1_ * normMile);

	return estimatePrice_;
}

double	EstimatePrice::predictPrice(const int& mileage)
{
	setMileage(mileage);
	double normMile = normalizeMile(mileage_);
	estimatePrice_ = theta0_ + (theta1_ * normMile);

	return estimatePrice_;
}
