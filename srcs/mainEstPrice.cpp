/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainLinReg.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:34:13 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/18 10:41:38 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "estimatePrice.h"

int main(int av, char** ag)
{
		/* ESTIMATE PRICE */
	EstimatePrice ep;
	cout << ep.predictPrice(1200);
	cout << ep.theta0() << '\t' << ep.theta1() << '\n'
		<< ep.maxMile() << '\t' << ep.minMile() << '\n'
		<< ep.predictPrice(2300) << '\n';
		
	return 0;
}
