/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainEstPrice.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 08:51:55 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/21 10:38:47 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "estimatePrice.h"

int main(int av, char** ag)
{
	if (av != 1){
		EstimatePrice ep;
		for (int i = 1; i < av; i++){
			int errorCode = 0;
			cout << ep.predictPrice(ag[i], errorCode);
			if (errorCode == 1){
				cout << "\t\tWarning: Value " << ag[i] << " out of data.";
			}
			cout << "\n";
		}
	}
	return 0;
}
