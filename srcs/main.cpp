/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainLinReg.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:34:13 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/20 11:21:45 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linearRegression.h"
#include "estimatePrice.h"
#include "plot.h"

int main(int av, char** ag)
{
		/* LINEAR REGRESSION */
	LinearRegression lr;
	lr.setFlags(1);
	lr.train();

	vector<double> test = lr.mileage();
	vector<double> test2 = lr.price();
	double theta0 = lr.theta0();
	double theta1 = lr.theta1();
	cout << "\n\n" << theta0 << '\t' << theta1 << "\n\n" << lr.accuracy() << "\n\n";

		/* ESTIMATE PRICE */
	EstimatePrice ep;
	cout << ep.theta0() << '\t' << ep.theta1() << '\n'
		<< ep.predictPrice(2300) << "\n\n";

	/* return (0); */




		/* PLOT */

	Plot pl;
	pl.initialize();
	pl.subplot2grid(2, 1);
	vector<string> plot1;
	plot1.push_back("label");
	plot1.push_back("theta error");
	plot1.push_back("linewidth");
	plot1.push_back("3.0");
	pl.param_plot(plot1, lr.thetaError(), "r");
	vector<string> titlePlot;
	titlePlot.push_back("fontweight");
	titlePlot.push_back("bold");
	titlePlot.push_back("loc");
	titlePlot.push_back("left");
	pl.title("Theta error", titlePlot);
	pl.xlabel("Cycles");
	pl.ylabel("Error");
	pl.legend();

	pl.subplot2grid(2, 1, 1);
	vector<double>	predictVect;
	predictVect.emplace_back(ep.predictPrice(lr.minMile()));
	predictVect.emplace_back(ep.predictPrice(lr.maxMile()));
	vector<double>	minMaxVect;
	minMaxVect.emplace_back(lr.minMile());
	minMaxVect.emplace_back(lr.maxMile());
	vector<string> plot2;
	plot2.push_back("label");
	plot2.push_back("predicted price");
	plot2.push_back("linewidth");
	plot2.push_back("3.0");
	pl.param_plot(plot2, minMaxVect, predictVect, "r");

	vector<string> plot3;
	plot3.push_back("label");
	plot3.push_back("data");
	pl.param_plot(plot3, lr.mileage(), lr.price(), "o");
	vector<string> plot4;
	pl.xlabel("Km");
	pl.ylabel("Price");
	pl.title("Prediction", titlePlot);
	pl.legend();
	pl.tight_layout();
	pl.show();
		
	return 0;
}
