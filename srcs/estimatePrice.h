/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearRegression.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:01:33 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/12 12:14:07 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

class LinearRegression
{
	private:
		double			theta0_;
		double			theta1_;
		double			learningRate_;
		vector<double>	mileage_;
		vector<double>	price_;
		int				maxMile_;
		int				minMile_;
		string			dataInfo_;

		void			getData();
		void			setData(const string& line);
		void			normalizeMileage();
		void			createOutFile();

	public:
		LinearRegression():
			theta0_(0), theta1_(0), learningRate_(LEARNING_RATE), mileage_(0), price_(0), maxMile_(-1), minMile_(-1), dataInfo_()
			{
				getData();
			};
		void			linearRegression();
		double			normalize(const int& mileage);

		double			theta0() {return theta0_;}
		double			theta1() {return theta1_;}
		vector<double>	mileage() {return mileage_;}
		vector<double>	price() {return price_;}
};
