/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainLinReg.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:34:13 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/12 12:13:38 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linearRegression.h"
#include "estimatePrice.h"

int main(int av, char** ag)
{
	/* if (av == 1){ */
		LinearRegression lr;
		lr.linearRegression();

		vector<double> test = lr.mileage();
		vector<double> test2 = lr.price();
		double theta0 = lr.theta0();
		double theta1 = lr.theta1();

		cout << "\n\n" << theta0 << '\t' << theta1 << "\n\n";
		/* cout << "\n\n" << theta0 << '\t' << theta1 << '\t' << "\n\n" << theta0 + (theta1 * -1) << "\n\n"; */
		/* cout << "\n\n" << theta0 << '\t' << theta1 << '\t' << lr.normalize(22899) << "\n\n" << theta0 + (theta1 * lr.normalize(120000)) << "\n\n"; */
		/* for (int i = 0; test[i]; i++){ */
		/* 	cout << test[i] << '\t'; */
		/* 	cout << test2[i] << '\n'; */
		/* } */
	/* } */
	/* else { */
		EstimatePrice ep;
		cout << ep.theta0() << '\t' << ep.theta1() << '\n'
			<< ep.maxMile() << '\t' << ep.minMile() << '\n'
			<< ep.predictPrice(28000) << '\n';
		
	/* } */
	plt::plot({1,3,2,4});
    plt::show();
	return 0;
}
