/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearRegression.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:01:31 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/11 10:57:36 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linearRegression.h"

/* REMEMBER WHEN NO FILE!!!! */

void	LinearRegression::getData()
{
	ifstream file("files/data.csv");		//FILE_NAME
	
	string line = "";

	while (getline(file, line)){
		if (isdigit(line[0])){
			writeData(line);
		}
		else {
			dataInfo_ = line;
		}
	}
	file.close();
	normalizeMileage();
}

void	LinearRegression::writeData(string& line)
{
	int	delimeterPos = 0;
	if ((delimeterPos = line.find(',')))			//DELIMETER
	{
		string mileString = line.substr(0, delimeterPos); 
		string priceString = line.substr(delimeterPos + 1, line.size());
		int mileage = stoi(mileString);
		int price = stoi(priceString);
		mileage_.push_back(mileage);
		price_.push_back(price);
		if (mileage > mileMax_){
			mileMax_ = mileage;
		}
		if (mileMin_ == -1 || mileMin_ > mileage){
			mileMin_ = mileage;
		}
	}
}

void	LinearRegression::normalizeMileage()
{
	int divisor = mileMax_ - mileMin_;				//what if are the same?? or 0
	for (int i = 0; mileage_[i]; i++){
		mileage_[i] = (mileage_[i] - mileMin_) / divisor;
	}
}

double	LinearRegression::normalize(const int& mileage)			//WHY?
{
	cout << (mileage - mileMin_) / (mileMax_ - mileMin_);
	return (mileage - mileMin_) / (mileMax_ - mileMin_);
}

void	LinearRegression::linearRegression()
{
	int		size = price_.size();

	for(int j = 0; j < 10000; j++){				//CYCLES
		double tmpT0 = 0;
		double tmpT1 = 0;
		for (int i = 0; i < size; i++){
			double estimatePrice = theta0_ + (theta1_ * mileage_[i]);
			double error = estimatePrice - price_[i];
			tmpT0 += error;
			tmpT1 += error * mileage_[i];
		}
		theta0_ -= learningRate_ * 1/size * tmpT0;
		theta1_ -= learningRate_ * 1/size * tmpT1;
	}
}

int main()
{
	LinearRegression lr;
	lr.linearRegression();

	vector<double> test = lr.mileage();
	vector<double> test2 = lr.price();
	double theta0 = lr.theta0();
	double theta1 = lr.theta1();

	cout << "\n\n" << theta0 << '\t' << theta1 << '\t' << "\n\n" << theta0 + (theta1 * 0.7) << "\n\n";
	/* cout << "\n\n" << theta0 << '\t' << theta1 << '\t' << lr.normalize(22899) << "\n\n" << theta0 + (theta1 * lr.normalize(120000)) << "\n\n"; */
	/* for (int i = 0; test[i]; i++){ */
	/* 	cout << test[i] << '\t'; */
	/* 	cout << test2[i] << '\n'; */
	/* } */
	return 0;
}
