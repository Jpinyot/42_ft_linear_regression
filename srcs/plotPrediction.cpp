/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotPrediction.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 10:33:32 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/22 12:04:55 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plotPrediction.h"

void	PlotPrediction::plot_cost(const vector<double>& error)
{
	needShow_ = true;
	if (flags_ & (plotData | plotPrediction)){
		plt_.subplot2grid(2, 1);
		subPlot_ = true;
	}
	plt_.initialize();
	vector<string> plotParams;
	plotParams.push_back("label");
	plotParams.push_back("theta error");
	plotParams.push_back("linewidth");
	plotParams.push_back("3.0");
	plt_.param_plot(plotParams, error, "r");
	vector<string> titlePlot;
	titlePlot.push_back("fontweight");
	titlePlot.push_back("bold");
	titlePlot.push_back("loc");
	titlePlot.push_back("left");
	plt_.title("Theta error", titlePlot);
	plt_.xlabel("Cycles");
	plt_.ylabel("Error");
	plt_.legend();
}

void	PlotPrediction::plot_data(const vector<double>& x, const vector<double>& y)
{
	needShow_ = true;
	if (flags_ & plotCost){
		plt_.subplot2grid(2, 1, 1);
		subPlot_ = true;
	}
	else {
		plt_.initialize();
	}
	vector<string> plotParams;
	plotParams.push_back("label");
	plotParams.push_back("linear regression");
	plotParams.push_back("linewidth");
	plotParams.push_back("3.0");
	plt_.param_plot(plotParams, x, y, "r");
	plt_.legend();
}

void	PlotPrediction::plot_prediction()
{
	needShow_ = true;
	if (!(flags_ & plotData) && (flags_ & plotCost)){
		plt_.subplot2grid(2, 1, 1);
		subPlot_ = true;
	}
	else if (!(flags_ & plotData)){
		plt_.initialize();
	}
	vector<string> plotParams2;
	plotParams2.push_back("label");
	plotParams2.push_back("data");
	plt_.param_plot(plotParams2, dataMiles_, dataPrice_, "bo");

	vector<string> plotParams;
	plotParams.push_back("label");
	plotParams.push_back("predicted price");
	plotParams.push_back("linewidth");
	plotParams.push_back("3.0");
	plt_.param_plot(plotParams, inMiles_, inPrice_, "g^");

	plt_.xlabel("Km");
	plt_.ylabel("Price");
	vector<string> titlePlot;
	titlePlot.push_back("fontweight");
	titlePlot.push_back("bold");
	titlePlot.push_back("loc");
	titlePlot.push_back("left");
	plt_.title("Prediction", titlePlot);
	plt_.legend();

}

void		PlotPrediction::show_ifneed()
{
	if (subPlot_){
		plt_.tight_layout();
	}
	if (needShow_){
		plt_.show();
	}
}
