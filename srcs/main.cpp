/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainLinReg.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:34:13 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/22 12:15:37 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linearRegression.h"
#include "estimatePrice.h"
#include "plotPrediction.h"

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
	PlotPrediction plt;
	if (av > 1){
		flagsCnt = check_flags(ag[1]);
		plt.setFlags(flagsCnt);
		linearReg.setFlags(flagsCnt);
		linearReg.train();
		for (int i = flagsCnt == noFlags ? 1 : 2; i < av; i++){
			int errorCode = 0;
			double currentPrediction = estPrice.predictPrice(ag[i], errorCode);
			cout << currentPrediction;
			if (errorCode == 1){
				cout << "\t\tWarning: Value " << ag[i] << " out of data.";
			}
			else if (flagsCnt & plotPrediction) {
				plt.addInPrice(currentPrediction);
				plt.addInMiles(ag[i]);
			}
			cout << "\n";
		}
	}
	if (flagsCnt & plotCost){
		plt.plot_cost(linearReg.thetaError());
	}
	if (flagsCnt & plotData){
		vector<double>	predictVect;
		predictVect.emplace_back(estPrice.predictPrice(linearReg.minMile()));
		predictVect.emplace_back(estPrice.predictPrice(linearReg.maxMile()));
		vector<double>	minMaxVect;
		minMaxVect.emplace_back(linearReg.minMile());
		minMaxVect.emplace_back(linearReg.maxMile());
		plt.plot_data(minMaxVect, predictVect);
	}
	if (flagsCnt & plotPrediction){
		plt.setDataPrice(linearReg.price());
		plt.setDataMiles(linearReg.mileage());
		plt.plot_prediction();
	}
	if (flagsCnt & printAccuracy){
		print_accuracy(linearReg.accuracy());
	}
	plt.show_ifneed();
	return 0;
}
