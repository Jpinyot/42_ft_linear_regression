/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearRegression.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:01:31 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/22 09:21:56 by jpinyot          ###   ########.fr       */
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
	dataInfo_ = line;
	while (getline(file, line)){
		setData(line);
		mean_ += mileage_[dataSize_];
		dataSize_++;
	}
	mean_ /= dataSize_;
	file.close();
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
		strError.append(" unknow format.\n");
		strError.append("Expected format:\t[km],[price]");
    	throw runtime_error(strError);
	}
}

void	LinearRegression::calculateStdDesviation()
{
	double sumX = 0;
	for (int i = 0; i < mileage_.size(); i++){
		sumX += pow(mileage_[i] - mean_, 2);
	}
	stdDeviation_ = sqrt(sumX / dataSize_);
}

void	LinearRegression::normalizeMileage()
{
	calculateStdDesviation();
	for (int i = 0; mileage_[i]; i++){
		normMileage_.emplace_back((mileage_[i] - mean_) / stdDeviation_);
	}
}

void	LinearRegression::createOutFile()
{
	ofstream outFile(THETA_FILE);
	if (!outFile){
    	throw runtime_error("Error opening output file");
	}
	outFile << theta0_ << DELIMETER << theta1_ << '\n' << mean_ << DELIMETER <<
		stdDeviation_ << '\n' << std::endl;
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
		if (flags_ & plotCost){
			thetaError_.emplace_back(fabs(tmpT0));
		}
		theta0_ -= learningRate_ * 1/size * tmpT0;
		theta1_ -= learningRate_ * 1/size * tmpT1;
	}
	createOutFile();
}

string	LinearRegression::accuracy()
{
	LinearRegError accuracy;

	accuracy.setX(normMileage());
	accuracy.setY(price());
	accuracy.setTheta0(theta0());
	accuracy.setTheta1(theta1());
	accuracy.calculateError();

	return accuracy.explicidStr();
}
