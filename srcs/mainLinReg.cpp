/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainLinReg.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:34:13 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/18 10:47:54 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linearRegression.h"

int main(int av, char** ag)
{
		/* LINEAR REGRESSION */
	LinearRegression lr;
	lr.train();

	vector<double> test = lr.mileage();
	vector<double> test2 = lr.price();
	double theta0 = lr.theta0();
	double theta1 = lr.theta1();
	cout << "\n\n" << theta0 << '\t' << theta1 << "\n\n";
	return 0;
}
