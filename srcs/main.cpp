/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainLinReg.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:34:13 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/21 12:25:58 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linearRegression.h"
#include "estimatePrice.h"
#include "plot.h"

inline Flags	check_flags(const string& str)
{
	if (str.find('-') != 0){
		return noFlags;
	}
	int		cnt = 1;
	Flags 	flagsCnt = noFlags;
	if (str.find('c') != std::string::npos){
		flagsCnt = flagsCnt | plotCost;
		cnt += 1;
	}
	if (str.find('d') != std::string::npos){
		flagsCnt = flagsCnt | plotData;
		cnt += 1;
	}
	if (str.find('p') != std::string::npos){
		flagsCnt = flagsCnt | plotPrediction;
		cnt += 1;
	}
	if (str.find('a') != std::string::npos){
		flagsCnt = flagsCnt | printAccuracy;
		cnt += 1;
	}
	if (cnt == str.size()){
		return flagsCnt;
	}
	else {
		return noFlags;
	}
}


inline void	print_accuracy(const string& accuracy)
{
	cout << '\n' << accuracy;
}

int			main(int av, char** ag)
{
	Flags flagsCnt = noFlags;
	EstimatePrice estPrice;
	LinearRegression linearReg;
	vector<double> predictions = {};
	if (av > 1){
		flagsCnt = check_flags(ag[1]);
		cout << flagsCnt << '\n';
		linearReg.train();
		/* int i = flagsCnt ? 0 : -1; */
		for (int i = (flagsCnt != noFlags) ? 1 : 2; i < av; i++){
		cout << i;
		/* while (++i < av){ */
			int errorCode = 0;
			double currentPrediction = estPrice.predictPrice(ag[i], errorCode);
			cout << currentPrediction;
			if (errorCode == 1){
				predictions.emplace_back(currentPrediction);
				cout << "\t\tWarning: Value " << ag[i] << " out of data.";
			}
			cout << "\n";
		}
	}
	if (flagsCnt & plotCost && flagsCnt & plotPrediction){
		Plot pl;
		pl.initialize();
	}
	switch (flagsCnt)
	{
		case plotCost:
			/* plotCost(); */
			break;
		case plotData:
			break;
		case plotPrediction:
			break;
		case printAccuracy:
			print_accuracy(linearReg.accuracy());
			break;
		default :
			break;
	}
	return 0;
		/* LINEAR REGRESSION */
	LinearRegression lr;
	lr.setFlags(1);
	lr.train();

	/* vector<double> test = lr.mileage(); */
	/* vector<double> test2 = lr.price(); */
	/* double theta0 = lr.theta0(); */
	/* double theta1 = lr.theta1(); */
	/* cout << "\n\n" << theta0 << '\t' << theta1 << "\n\n" << lr.accuracy() << "\n\n"; */

		/* ESTIMATE PRICE */
	EstimatePrice ep;
	/* cout << ep.theta0() << '\t' << ep.theta1() << '\n' */
	/* 	<< ep.predictPrice(2300) << "\n\n"; */

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
	/* plot3.push_back("legend.numpoints"); */
	/* plot3.push_back("1"); */
	pl.param_plot(plot3, lr.mileage(), lr.price(), "bo");
	vector<string> plot4;
	pl.xlabel("Km");
	pl.ylabel("Price");
	pl.title("Prediction", titlePlot);
	vector<string> plot5;
	/* plot5.push_back("numpoints"); */
	/* plot5.push_back("1"); */
	/* pl.legend(plot5); */
	pl.legend();
	pl.tight_layout();
	pl.show();
		
	return 0;
}
