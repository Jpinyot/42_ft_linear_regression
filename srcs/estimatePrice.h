/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimatePrice.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:46:01 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/21 08:47:13 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

class EstimatePrice
{
	private:
		double			theta0_;
		double			theta1_;
		double			mean_;
		double			stdDeviation_;

		void			getData();
		void			setTheta(const string& line);
		void			setNormParam(const string& line);
		double			normalizeMile(const int& mileage);
		bool			isNumber(const string& s);

	public:
		EstimatePrice():
			theta0_(0), theta1_(0), mean_(0), stdDeviation_(0)
			{
				getData();
			};
		virtual	~EstimatePrice() {};
		double			predictPrice(const int& mileage, int& error);
		double			predictPrice(const int& mileage);
		double			predictPrice(const string& mileage, int& error);
		double			predictPrice(const string& mileage);

		inline double	theta0() {return theta0_;}
		inline double	theta1() {return theta1_;}
};
