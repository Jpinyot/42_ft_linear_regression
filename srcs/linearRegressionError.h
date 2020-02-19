/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearRegressionError.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 08:27:59 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/19 11:45:14 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

class LinearRegressionError
{
	private:
		vector<double>	x_;
		vector<double>	y_;
		vector<double>	yPred_;
		double			xMean_;
		double			yMean_;
		double			theta0_;
		double			theta1_;
		double			correlation_;
		double			MSE_;
		double			MAE_;
		double			RMSE_;
		double			RAE_;
		double			RRSE_;

		void	calculateCorrelation();
		void	predictY();

	public:
		LinearRegressionError(const vector<double>& x={}, const vector<double>& y={}, const double& theta0=0, const double& theta1=0):
			x_(x), y_(y), yPred_(0), xMean_(0), yMean_(0), theta0_(theta0), theta1_(theta1), correlation_(0), MSE_(0), MAE_(0), RMSE_(0), RAE_(0), RRSE_(0)
		{};
		virtual	~LinearRegressionError() {};
		void	calculateError();
		string	explicidStr();

		double	MSE() {return MSE_;}
		double	MAE() {return MAE_;}
		double	RMSE() {return RMSE_;}
		double	RAE() {return RAE_;}
		double	RRSE() {return RRSE_;}

		void	setX(const vector<double>& x) {x_ = x;}
		void	setY(const vector<double>& y) {y_ = y;}
		void	setTheta0(double theta0) {theta0_ = theta0;}
		void	setTheta1(double theta1) {theta1_ = theta1;}
};
