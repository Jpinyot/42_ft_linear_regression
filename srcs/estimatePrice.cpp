/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimatePrice.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:30:47 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/18 11:26:34 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "estimatePrice.h"

void	EstimatePrice::getData()
{
	ifstream file(THETA_FILE);
	if (!file){
		string strError;
		strError.append("Espected file ");
		strError.append(THETA_FILE);
		strError.append(" not found.");
    	throw runtime_error(strError);
	}
	
	string line = "";
	if (getline(file, line)){
		setTheta(line);
	}
	else{
		string strError;
		strError.append("File ");
		strError.append(THETA_FILE);
		strError.append(" missing information on first line.\n");
    	throw runtime_error(strError);
	}
	if (getline(file, line)){
		setMinMaxMile(line);
	}
	else{
		string strError;
		strError.append("File ");
		strError.append(THETA_FILE);
		strError.append(" missing information on second line.\n");
    	throw runtime_error(strError);
	}
	file.close();
}

void	EstimatePrice::setTheta(const string& line)
{
	int	delimeterPos = -1;
	if ((delimeterPos = line.find(DELIMETER)) != -1)
	{
		string theta0String = line.substr(0, delimeterPos); 
		string theta1String = line.substr(delimeterPos + 1, line.size());
		theta0_ = stod(theta0String);
		theta1_ = stod(theta1String);
	}
	else{
		string strError;
		strError.append("File ");
		strError.append(THETA_FILE);
		strError.append(" unknow format on first line.\n");
		strError.append("Expected format:\t[theta0 value],[theta1 value]");
    	throw runtime_error(strError);
	}
}

void	EstimatePrice::setMinMaxMile(const string& line)
{
	int	delimeterPos = 0;
	if ((delimeterPos = line.find(DELIMETER)))
	{
		string maxMile = line.substr(0, delimeterPos); 
		string minMile = line.substr(delimeterPos + 1, line.size());
		maxMile_ = stoi(maxMile);
		minMile_ = stoi(minMile);
	}
	else{
		string strError;
		strError.append("File ");
		strError.append(THETA_FILE);
		strError.append(" unknow format on second line.\n");
		strError.append("Expected format:\n[max mileage value],[min mileage value]");
    	throw runtime_error(strError);
	}
	if (maxMile_ == minMile_){
		string strError;
		strError.append("On file ");
		strError.append(THETA_FILE);
		strError.append(": espected diferent values from max mileage and min mileage.\n");
    	throw runtime_error(strError);
	}
}

double	EstimatePrice::normalizeMile(const int& mileage)
{
	double normMile = (mileage - minMile_) / (maxMile_ - minMile_);
	return normMile;
}

double	EstimatePrice::predictPrice(const int& mileage)
{
	double normMile = normalizeMile(mileage);
	estimatePrice_ = theta0_ + (theta1_ * normMile);

	return estimatePrice_;
}
