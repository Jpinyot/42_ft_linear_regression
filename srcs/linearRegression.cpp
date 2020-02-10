/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearRegression.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:01:31 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/10 12:23:35 by jpinyot          ###   ########.fr       */
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

int main()
{
	LinearRegression lr;

	vector<int> test = lr.mileage();
	vector<int> test2 = lr.price();

	for (int i = 0; test[i]; i++){
		cout << test[i] << '\t';
		cout << test2[i] << '\n';

	}

	return 0;
}
