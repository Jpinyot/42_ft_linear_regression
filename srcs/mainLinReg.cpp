/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainLinReg.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:34:13 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/15 12:41:55 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linearRegression.h"
#include "estimatePrice.h"
#include "plot.h"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

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

	/* plt::subplot2grid(2, 1); */
	/* plt::plot(lr.thetaError(), "r"); */
	/* /1* plt::named_plot("HOLA", lr.thetaError(), "r"); *1/ */
	/* plt::subplot2grid(2, 1, 1); */
	/* plt::named_plot("HOLA", lr.price(), lr.mileage(), "o"); */
	/* plt::legend(); */
	/* plt::show(); */





	Plot pl;
	pl.subplot2grid(2, 1);
	/* pl.plot(lr.thetaError()); */
	pl.named_plot("HOLI", lr.thetaError(), "r");
	pl.legend();
	/* map<string, string> tick; */
	/* tick.insert(pair<string, string>("width","6.0")); */
	/* tick.insert(pair<string, string>("direction","inout")); */
	/* pl.tick_params(tick); */
	/* pl.ylim(160000, 6000); */
	pl.subplot2grid(2, 1, 1);
	pl.plot(lr.price(), lr.mileage(), "o");
	pl.plot({8000}, {26000}, "r^");
	pl.show();
		
	return 0;
}
