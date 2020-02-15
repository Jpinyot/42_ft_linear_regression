/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearRegression.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:01:31 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/15 11:47:45 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linearRegression.h"

/* REMEMBER WHEN NO FILE!!!! */

void	LinearRegression::getData()
{
	ifstream file(DATA_FILE);		//FILE_NAME, when no file, must be an error
	
	string line = "";

	while (getline(file, line)){
		if (isdigit(line[0])){
			setData(line);
		}
		else {
			dataInfo_ = line;
		}
	}
	file.close();
	normalizeMileage();
}

void	LinearRegression::setData(const string& line)
{
	int	delimeterPos = 0;
	if ((delimeterPos = line.find(DELIMETER)))			//DELIMETER
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
		/* if (price > maxPrice_){ */
		/* 	maxPrice_ = price; */
		/* } */
		/* if (minPrice_ == -1 || price < minPrice_){ */
		/* 	minPrice_ = price; */
		/* } */
	}
}

void	LinearRegression::normalizeMileage()
{
	int divisor = maxMile_ - minMile_;				//what if are the same?? or 0
	for (int i = 0; mileage_[i]; i++){
		normMileage_.emplace_back((mileage_[i] - minMile_) / divisor);
	}
}

void	LinearRegression::createOutFile()
{
	ofstream outFile(THETA_FILE);
	outFile << theta0_ << ',' << theta1_ << '\n' << maxMile_ << ',' << minMile_ << '\n' << std::endl;
	outFile.close();
}

double	LinearRegression::normalize(const int& mileage)			//WHY?
{
	cout << (mileage - minMile_) / (maxMile_ - minMile_);
	return (mileage - minMile_) / (maxMile_ - minMile_);
}

void	LinearRegression::linearRegression()
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
	if (flags_ & 1){
		/* plotThetaError(thetaError); */
		/* thread plotThread(plotThetaError, thetaError); */
		/* plotThread.join(); */
		/* delete plotThread; */
	}
	createOutFile();
}
