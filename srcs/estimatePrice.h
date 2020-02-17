/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearRegression.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:01:33 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/17 08:22:17 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

class EstimatePrice
{
	private:
		double			theta0_;
		double			theta1_;
		double			estimatePrice_;
		int				mileage_;
		int				maxMile_;
		int				minMile_;

		void			getData();
		void			setTheta(const string& line);
		void			setMinMaxMile(const string& line);
		double			normalizeMile(const int& mileage);

		void			setMileage(const int& mileage) {mileage_ = mileage;};

	public:
		EstimatePrice():
			theta0_(0), theta1_(0), estimatePrice_(0), mileage_(0), maxMile_(-1), minMile_(-1)
			{
				getData();
			};
		double			predictPrice();
		double			predictPrice(const int& mileage);

		double			theta0() {return theta0_;}
		double			theta1() {return theta1_;}
		double			mileage() {return mileage_;}
		int				maxMile() {return maxMile_;}
		int				minMile() {return minMile_;}
		vector<double>	predictionVector();
		vector<double>	minMaxVector();
};
