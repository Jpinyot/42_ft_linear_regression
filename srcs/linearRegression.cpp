/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearRegression.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:01:31 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/11 08:45:21 by jpinyot          ###   ########.fr       */
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
}

void	LinearRegression::writeData(string& line)
{
	int	delimeterPos = 0;
	if ((delimeterPos = line.find(',')))			//DELIMETER
	{
		string mileage = line.substr(0, delimeterPos); 
		string price = line.substr(delimeterPos + 1, line.size());
		mileage_.push_back(stoi(mileage));
		price_.push_back(stoi(price));
	}
}

void	LinearRegression::linearRegression()
{
	int		size = price_.size();
	/* while(1){ */
	for(int j = 0; j < 1; j++){
		/* cout << '&'; */
		for (int i = 0; i < size; i++){
			double estimatePrice = theta0_ + (theta1_ * mileage_[i]);
			double error = estimatePrice - price_[i];
			theta0_ = theta0_ - learningRate_ * error;
			theta1_ = theta1_ - learningRate_ * error * mileage_[i];
			cout << theta0_ << '\t' << theta1_ << '\t' << estimatePrice - price_[i] << '\n';
		}
	}
}

int main()
{
	LinearRegression lr;
	lr.linearRegression();

	vector<int> test = lr.mileage();
	vector<int> test2 = lr.price();
	double theta0 = lr.theta0();
	double theta1 = lr.theta1();

	cout << "\n\n" << theta0 << '\t' << theta1 << "\n\n" << theta0 + (theta1 * 22899) << "\n\n";
	/* for (int i = 0; test[i]; i++){ */
	/* 	cout << test[i] << '\t'; */
	/* 	cout << test2[i] << '\n'; */
	/* } */
	return 0;
}
