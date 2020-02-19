/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearRegressionError.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 08:28:10 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/19 11:47:43 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linearRegressionError.h"

void	LinearRegressionError::calculateCorrelation()
{
	int		size = x_.size();		
	double	x = 0;
	double	y = 0;
	double	xy = 0;
	double	xPow = 0;
	double	yPow = 0;

	for (int i = 0; i < size; i++){
		x += x_[i];
		y += y_[i];
		xy += x_[i] * y_[i];
		xPow += pow(x_[i], 2);
		yPow += pow(y_[i], 2);
	}
	double divisor = size * xy - x * y;
	double dividend = sqrt((size * xPow - pow(x, 2)) * (size * yPow - pow(y, 2)));
	correlation_ = divisor / dividend;
}

void	LinearRegressionError::predictY()
{
	double xSum = 0;
	double ySum = 0;
	for (int i = 0; i < x_.size(); i++){
		yPred_.emplace_back(theta0_ + (theta1_ * x_[i]));
		xSum += x_[i];
		ySum += y_[i];
	}
	xMean_ /= y_.size();
	yMean_ /= y_.size();
}

void	LinearRegressionError::calculateError()
{
	predictY();
	calculateCorrelation();
	int		size = y_.size();
	double	SE = 0;
	double	SM = 0;
	double	AE = 0;
	double	AM = 0;

	for (int i = 0; i < size; i++){
		SE += pow(y_[i] - yPred_[i], 2);
		SM += pow(yMean_ - y_[i], 2);
		AE += abs(y_[i] - yPred_[i]);
		AM += abs(yMean_ - y_[i]);
	}
	MSE_ = SE / size;
	MAE_ = AE / size;
	RMSE_ = sqrt(MSE_);
	RAE_ = AE / AM;
	RRSE_ = sqrt(SE / SM);
}

string	LinearRegressionError::explicidStr()
{
	string ret;

	ret = "Correlation:\t\t\t\t" + to_string(correlation_);
	ret.append("\nMSE(Mean Square Error):\t\t\t" + to_string(MSE_));
	ret.append("\nMAE(Mean Absolut Error):\t\t" + to_string(MAE_));
	ret.append("\nRMSE(Root Mean Square Error):\t\t" + to_string(RMSE_));
	ret.append("\nRAE(Relative Absolut Error):\t\t" + to_string(RAE_));
	ret.append("\nRRSE(Relative Root Square Error):\t" + to_string(RRSE_));

	return ret;
}
