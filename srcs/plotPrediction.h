/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotPrediction.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 10:31:59 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/22 12:04:49 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "plot.h"

class	PlotPrediction
{
	private:
		Plot			plt_;
		Flags			flags_;
		bool			needShow_;
		bool			subPlot_;
		vector<double>	inPrice_;
		vector<double>	inMiles_;
		vector<double>	dataPrice_;
		vector<double>	dataMiles_;

	public:
		PlotPrediction():
			plt_(), flags_(noFlags), needShow_(false), subPlot_(false), inPrice_(0), inMiles_(0), dataPrice_(0), dataMiles_(0)
		{
			plt_.initialize();
		};
		void		plot_cost(const vector<double>& error);
		void		plot_data(const vector<double>& x, const vector<double>& y);
		void		plot_prediction();
		void		show_ifneed();

		inline void	setFlags(const Flags& flags) {flags_ = flags;}
		inline void	setInPrice(const vector<double>& inPrice) {inPrice_ = inPrice;};
		inline void	setInMiles(const vector<double>& inMiles) {inMiles_ = inMiles;};
		inline void	setDataPrice(const vector<double>& dataPrice) {dataPrice_ = dataPrice;};
		inline void	setDataMiles(const vector<double>& dataMiles) {dataMiles_ = dataMiles;};

		inline void	addInPrice(const double& nextVal) {inPrice_.emplace_back(nextVal);}
		inline void	addInMiles(const double& nextVal) {inMiles_.emplace_back(nextVal);}
		inline void	addInMiles(const string& nextValStr) {inMiles_.emplace_back(atoi(nextValStr.c_str()));}
};
