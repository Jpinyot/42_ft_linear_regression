/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimatePrice.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:46:01 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/20 11:15:20 by jpinyot          ###   ########.fr       */
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
		/* int				maxMile_; */
		/* int				minMile_; */

		void			getData();
		void			setTheta(const string& line);
		/* void			setMinMaxMile(const string& line); */
		void			setNormParam(const string& line);
		double			normalizeMile(const int& mileage);

	public:
		EstimatePrice():
			theta0_(0), theta1_(0), mean_(0), stdDeviation_(0)
			/* theta0_(0), theta1_(0), maxMile_(-1), minMile_(-1) */
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
		/* inline int		maxMile() {return maxMile_;} */
		/* inline int		minMile() {return minMile_;} */
};
