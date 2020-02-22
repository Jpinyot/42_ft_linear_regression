/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimatePrice.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:30:47 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/21 08:54:41 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "estimatePrice.h"

///WHAT WHEN INPUT IS BOOOL

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
		setNormParam(line);
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

void	EstimatePrice::setNormParam(const string& line)
{
	int	delimeterPos = 0;
	if ((delimeterPos = line.find(DELIMETER)))
	{
		string mean = line.substr(0, delimeterPos); 
		string stdDeviation = line.substr(delimeterPos + 1, line.size());
		mean_ = stod(mean);
		stdDeviation_ = stod(stdDeviation);
	}
	else{
		string strError;
		strError.append("File ");
		strError.append(THETA_FILE);
		strError.append(" unknow format on second line.\n");
		strError.append("Expected format:\n[mean],[Standard Deviation]");
    	throw runtime_error(strError);
	}
}

double	EstimatePrice::normalizeMile(const int& mileage)
{
	return (mileage - mean_) / stdDeviation_;
}

bool EstimatePrice::isNumber(const string& s)
{
	return !s.empty() && find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

double	EstimatePrice::predictPrice(const string& mileage, int& error)
{
	if (isNumber(mileage)){
		return predictPrice(atoi(mileage.c_str()), error);
	}
	else {
		string strError;
		strError.append("EstimatePrice::predictPrice(const string& s) unespected char.\n");
    	throw runtime_error(strError);
	}

}

double	EstimatePrice::predictPrice(const string& mileage)
{
	if (isNumber(mileage)){
		return predictPrice(atoi(mileage.c_str()));
	}
	else {
		string strError;
		strError.append("EstimatePrice::predictPrice(const string& s) unespected char.\n");
    	throw runtime_error(strError);
	}

}

double	EstimatePrice::predictPrice(const int& mileage, int& error)
{
	if (mileage >= 0){
		double normMile = normalizeMile(mileage);
		double predictedPrice = theta0_ + (theta1_ * normMile);
		if (predictedPrice < 0){
			error = 1;
		}
		return predictedPrice;
	}
	else {
		string strError;
		strError.append("EstimatePrice::predictPrice espected postive value as input.\n");
    	throw runtime_error(strError);
	}
}

double	EstimatePrice::predictPrice(const int& mileage)
{
	if (mileage >= 0){
		double normMile = normalizeMile(mileage);
		return theta0_ + (theta1_ * normMile);
	}
	else {
		string strError;
		strError.append("EstimatePrice::predictPrice espected postive value as input.\n");
    	throw runtime_error(strError);
	}
}
