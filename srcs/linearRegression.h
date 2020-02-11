/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearRegression.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:01:33 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/11 08:45:22 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <ctype.h>

#define FILE_NAME "files/data.csv"
#define DELIMETER ','
#define LEARING_RATE 0.2

using namespace std;

class LinearRegression
{
	private:
		double			theta0_;
		double			theta1_;
		double			learningRate_;
		vector<int>		mileage_;
		vector<int>		price_;
		string			dataInfo_;

		void	getData();
		void	writeData(string& line);

	public:
		LinearRegression():
			theta0_(0), theta1_(0), learningRate_(0.01), mileage_(0), price_(0), dataInfo_()
			{
				getData();
			};
		void		linearRegression();

		double		theta0() {return theta0_;}
		double		theta1() {return theta1_;}
		vector<int>	mileage() {return mileage_;}
		vector<int>	price() {return price_;}
};
