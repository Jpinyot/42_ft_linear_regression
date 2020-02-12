/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimatePrice.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:28:36 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/10 12:23:38 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "theta.h"

using namespace std;

class EstimatePrice
{
	private:
		float	theta0_;
		float	theta1_;
		int		mileage_;
		float	estimatePrice_;
		/* theta	thetas_; */

	public:

		EstimatePrice(int mileage):
			theta0_(0), theta1_(0), mileage_(mileage), estimatePrice_(0)
			/* theta0_(thetas_.theta0), theta1_(thetas_.theta1), mileage_(mileage), estimatePrice_(0) */
		{
			estimatePrice_ = theta0_ + (theta1_ * mileage_);
		}
		float	theta0() {return theta0_;}
		float	theta1() {return theta1_;}
};
