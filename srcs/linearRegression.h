/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearRegression.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:01:33 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/20 11:20:22 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "linearRegError.h"

class LinearRegression
{
	private:
		int				flags_;
		double			theta0_;
		double			theta1_;
		double			learningRate_;
		vector<double>	mileage_;
		vector<double>	normMileage_;
		vector<double>	price_;
		vector<double>	thetaError_;
		double			mean_;
		double			stdDeviation_;
		double			dataSize_;
		int				maxMile_;
		int				minMile_;
		string			dataInfo_;

		void		getData();
		void		setData(const string& line);
		inline void	calculateStdDesviation();
		void		normalizeMileage();
		void		createOutFile();

	public:
		LinearRegression(int flags=0):
			flags_(flags), theta0_(0), theta1_(0), learningRate_(LEARNING_RATE), mileage_(0), normMileage_(0), price_(0), mean_(0), stdDeviation_(0), dataSize_(0), maxMile_(-1), minMile_(-1), dataInfo_()
			/* flags_(flags), theta0_(0), theta1_(0), learningRate_(LEARNING_RATE), mileage_(0), normMileage_(0), price_(0), maxMile_(-1), minMile_(-1), dataInfo_() */
			{
				getData();
				if (flags_ & 1){
					thetaError_.reserve(CYCLES);
				}
			};
		virtual	~LinearRegression() {};
		void					train();
		string					accuracy();

		inline double			theta0() {return theta0_;}
		inline double			theta1() {return theta1_;}
		inline int				maxMile() {return maxMile_;}
		inline int				minMile() {return minMile_;}
		inline double			mean() {return mean_;}
		inline double			stdDeviation() {return stdDeviation_;}
		inline int				dataSize() {return dataSize_;}
		inline vector<double>	mileage() {return mileage_;}
		inline vector<double>	normMileage() {return normMileage_;}
		inline vector<double>	price() {return price_;}
		inline vector<double>	thetaError() {return thetaError_;}

		inline void				setFlags(int flags) {flags_ = flags_ | flags;}
};
