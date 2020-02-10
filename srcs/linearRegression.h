/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearRegression.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:01:33 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/10 12:23:35 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <ctype.h>

#define FILE_NAME "files/data.csv"
#define DELIMETER ','

using namespace std;

class LinearRegression
{
	private:
		float			theta0_;
		float			theta1_;
		vector<int>		mileage_;
		vector<int>		price_;
		string			dataInfo_;

		void	getData();
		void	writeData(string& line);

	public:
		LinearRegression():
			theta0_(0), theta1_(0), mileage_(0), price_(0), dataInfo_()
			{
				getData();
			};
		void		linearRegression();
		vector<int>	mileage() {return mileage_;}
		vector<int>	price() {return price_;}
};
