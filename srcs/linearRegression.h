/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearRegression.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:01:33 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/11 10:53:32 by jpinyot          ###   ########.fr       */
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
#define CYRCLES 10000

using namespace std;

class LinearRegression
{
	private:
		double			theta0_;
		double			theta1_;
		double			learningRate_;
		vector<double>	mileage_;
		vector<double>	price_;
		int				mileMax_;
		int				mileMin_;
		string			dataInfo_;

		void	getData();
		void	writeData(string& line);
		void	normalizeMileage();

	public:
		LinearRegression():
			theta0_(0), theta1_(0), learningRate_(0.02), mileage_(0), price_(0), mileMax_(-1), mileMin_(-1), dataInfo_()
			{
				getData();
			};
		void		linearRegression();
		double		normalize(const int& mileage);

		double			theta0() {return theta0_;}
		double			theta1() {return theta1_;}
		vector<double>	mileage() {return mileage_;}
		vector<double>	price() {return price_;}
};
