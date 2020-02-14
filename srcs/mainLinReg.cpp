/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainLinReg.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:34:13 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/14 12:39:41 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linearRegression.h"
#include "estimatePrice.h"
#include "plot.h"

int main(int av, char** ag)
{
		/* LINEAR REGRESSION */
	LinearRegression lr;
	lr.linearRegression();

	vector<double> test = lr.mileage();
	vector<double> test2 = lr.price();
	double theta0 = lr.theta0();
	double theta1 = lr.theta1();
	cout << "\n\n" << theta0 << '\t' << theta1 << "\n\n";

		/* ESTIMATE PRICE */
	EstimatePrice ep;
	cout << ep.theta0() << '\t' << ep.theta1() << '\n'
		<< ep.maxMile() << '\t' << ep.minMile() << '\n'
		<< ep.predictPrice(2300) << '\n';

		/* PLOT */
	Plot pl;
	pl.subplot2grid(2, 1);
	map<string, string> tick;
	/* tick.insert(pair<string, string>("axis","x")); */
	tick.insert(pair<string, string>("direction","inout"));
	pl.tick_params(tick);
	pl.plot(lr.thetaError());
	pl.subplot2grid(2, 1, 1);
	pl.plot(lr.price(), lr.mileage(), "o");
	pl.show();
		
	return 0;
}
