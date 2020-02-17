/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainLinReg.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:34:13 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/17 11:50:38 by jpinyot          ###   ########.fr       */
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

	plt::subplot2grid(2, 1);
	plt::plot(lr.thetaError(), "r");
	plt::subplot2grid(2, 1, 1);
	plt::named_plot("HOLA", lr.price(), lr.mileage(), "o");
	plt::legend();
	plt::tight_layout();
	plt::show();





	/* Plot pl; */
	/* pl.initialize(); */
	/* pl.subplot2grid(2, 1); */
	/* /1* vector<string> subplotadj; *1/ */
	/* /1* subplotadj.push_back("constrained_layout"); *1/ */
	/* /1* subplotadj.push_back("true"); *1/ */
	/* /1* subplotadj.push_back("bottom"); *1/ */
	/* /1* subplotadj.push_back("15"); *1/ */
	/* /1* pl.subplots_adjust(subplotadj); *1/ */
	/* vector<string> plot1; */
	/* plot1.push_back("label"); */
	/* plot1.push_back("theta error"); */
	/* plot1.push_back("linewidth"); */
	/* plot1.push_back("3.0"); */
	/* pl.param_plot(plot1, lr.thetaError(), "r"); */
	/* vector<string> titlePlot; */
	/* titlePlot.push_back("fontweight"); */
	/* titlePlot.push_back("bold"); */
	/* titlePlot.push_back("loc"); */
	/* titlePlot.push_back("left"); */
	/* pl.title("Theta error", titlePlot); */
	/* pl.xlabel("Cycles"); */
	/* pl.ylabel("Error"); */
	/* /1* pl.axis("tight"); *1/ */
	/* pl.legend(); */

	/* pl.subplot2grid(2, 1, 1); */
	/* /1* pl.subplots_adjust(subplotadj); *1/ */
	/* vector<string> plot2; */
	/* plot2.push_back("label"); */
	/* plot2.push_back("predicted price"); */
	/* plot2.push_back("linewidth"); */
	/* plot2.push_back("3.0"); */
	/* pl.param_plot(plot2, ep.minMaxVector(), ep.predictionVector(), "r"); */
	/* vector<string> plot3; */
	/* plot3.push_back("label"); */
	/* plot3.push_back("data"); */
	/* pl.param_plot(plot3, lr.mileage(), lr.price(), "o"); */
	/* vector<string> plot4; */
	/* /1* plot4.push_back("label"); *1/ */
	/* /1* plot4.push_back("predicted price"); *1/ */
	/* pl.xlabel("Miles"); */
	/* pl.ylabel("Price"); */
	/* pl.title("Prediction", titlePlot); */
	/* /1* pl.axis("tight"); *1/ */
	/* pl.legend(); */
	/* pl.tight_layout(); */
	/* /1* pl.set_tight_layout(true); *1/ */
	/* pl.show(); */
		
	return 0;
}
