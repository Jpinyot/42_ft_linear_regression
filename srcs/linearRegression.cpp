/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearRegression.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:01:31 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/18 11:14:52 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linearRegression.h"

void	LinearRegression::getData()
{
	ifstream file(DATA_FILE);
	string line = "";
	if (!file || !getline(file, line)){
		string strError;
		strError.append("Espected file ");
		strError.append(DATA_FILE);
		strError.append(" not found.");
    	throw runtime_error(strError);
	}
	else {
		dataInfo_ = line;
	}
	while (getline(file, line)){
		setData(line);
	}
	file.close();
	if (maxMile_ == minMile_){
		string strError;
		strError.append("On file ");
		strError.append(THETA_FILE);
		strError.append(": espected diferent values from max mileage and min mileage.\n");
    	throw runtime_error(strError);
	}
	normalizeMileage();
}

void	LinearRegression::setData(const string& line)
{
	int	delimeterPos = -1;
	if ((delimeterPos = line.find(DELIMETER)) != -1)
	{
		string mileString = line.substr(0, delimeterPos); 
		string priceString = line.substr(delimeterPos + 1, line.size());
		int mileage = stoi(mileString);
		int price = stoi(priceString);
		mileage_.emplace_back(mileage);
		price_.emplace_back(price);
		if (mileage > maxMile_){
			maxMile_ = mileage;
		}
		if (minMile_ == -1 || mileage < minMile_){
			minMile_ = mileage;
		}
	}
	else{
		string strError;
		strError.append("File ");
		strError.append(DATA_FILE);
		strError.append(" unknow format on first line.\n");
		strError.append("Expected format:\t[km],[price]");
    	throw runtime_error(strError);
	}
}

void	LinearRegression::normalizeMileage()
{
	int divisor = maxMile_ - minMile_;
	for (int i = 0; mileage_[i]; i++){
		normMileage_.emplace_back((mileage_[i] - minMile_) / divisor);
	}
}

void	LinearRegression::createOutFile()
{
	ofstream outFile(THETA_FILE);
	if (!outFile){
    	throw runtime_error("Error opening output file");
	}
	outFile << theta0_ << ',' << theta1_ << '\n' << maxMile_ << ',' << minMile_ << '\n' << std::endl;
	outFile.close();
}

void	LinearRegression::train()
{
	int		size = price_.size();

	for(int j = 0; j < CYCLES; j++){
		double tmpT0 = 0;
		double tmpT1 = 0;
		for (int i = 0; i < size; i++){
			double estimatePrice = theta0_ + (theta1_ * normMileage_[i]);
			double error = estimatePrice - price_[i];
			tmpT0 += error;
			tmpT1 += error * normMileage_[i];
		}
		if (flags_ & 1){
			thetaError_.emplace_back(fabs(tmpT0));
		}
		theta0_ -= learningRate_ * 1/size * tmpT0;
		theta1_ -= learningRate_ * 1/size * tmpT1;
	}
	createOutFile();
}
