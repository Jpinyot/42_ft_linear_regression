/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearRegression.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:01:33 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/18 10:43:42 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

class EstimatePrice
{
	private:
		double			theta0_;
		double			theta1_;
		double			estimatePrice_;
		int				maxMile_;
		int				minMile_;

		void			getData();
		void			setTheta(const string& line);
		void			setMinMaxMile(const string& line);
		double			normalizeMile(const int& mileage);

	public:
		EstimatePrice():
			theta0_(0), theta1_(0), estimatePrice_(0), maxMile_(-1), minMile_(-1)
			{
				getData();
			};
		virtual	~EstimatePrice() {};
		double			predictPrice(const int& mileage);

		inline double	theta0() {return theta0_;}
		inline double	theta1() {return theta1_;}
		inline int		maxMile() {return maxMile_;}
		inline int		minMile() {return minMile_;}
};
