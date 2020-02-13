/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linearRegression.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:01:31 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/13 12:10:53 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linearRegression.h"

/* REMEMBER WHEN NO FILE!!!! */

void	LinearRegression::getData()
{
	ifstream file(DATA_FILE);		//FILE_NAME, when no file, must be an error
	
	string line = "";

	while (getline(file, line)){
		if (isdigit(line[0])){
			setData(line);
		}
		else {
			dataInfo_ = line;
		}
	}
	file.close();
	normalizeMileage();
}

void	LinearRegression::setData(const string& line)
{
	int	delimeterPos = 0;
	if ((delimeterPos = line.find(DELIMETER)))			//DELIMETER
	{
		string mileString = line.substr(0, delimeterPos); 
		string priceString = line.substr(delimeterPos + 1, line.size());
		int mileage = stoi(mileString);
		int price = stoi(priceString);
		mileage_.emplace_back(mileage);
		price_.emplace_back(price);
		if (mileage > maxMile_){
			maxMile_ = mileage;
		}
		if (minMile_ == -1 || mileage < minMile_){
			minMile_ = mileage;
		}
	}
}

void	LinearRegression::normalizeMileage()
{
	int divisor = maxMile_ - minMile_;				//what if are the same?? or 0
	for (int i = 0; mileage_[i]; i++){
		mileage_[i] = (mileage_[i] - minMile_) / divisor;
	}
}

void	LinearRegression::createOutFile()
{
	ofstream outFile(THETA_FILE);
	outFile << theta0_ << ',' << theta1_ << '\n' << maxMile_ << ',' << minMile_ << '\n' << std::endl;
	outFile.close();
}

double	LinearRegression::normalize(const int& mileage)			//WHY?
{
	cout << (mileage - minMile_) / (maxMile_ - minMile_);
	return (mileage - minMile_) / (maxMile_ - minMile_);
}

PyObject* get_array(const std::vector<double>& v)
{
    /* detail::_interpreter::get();    //interpreter needs to be initialized for the numpy commands to work */
    NPY_TYPES type = NPY_DOUBLE;
    if (type == NPY_NOTYPE)
    {
        std::vector<double> vd(v.size());
        npy_intp vsize = v.size();
        std::copy(v.begin(),v.end(),vd.begin());
        PyObject* varray = PyArray_SimpleNewFromData(1, &vsize, NPY_DOUBLE, (void*)(vd.data()));
        return varray;
    }

    npy_intp vsize = v.size();
    PyObject* varray = PyArray_SimpleNewFromData(1, &vsize, type, (void*)(v.data()));		//SEGFAULT https://stackoverflow.com/questions/30357115/pyarray-simplenewfromdata-example
		write(1, "$", 1);
    return varray;
}

void	plotThetaError(const vector<double>& y)
{

	/* INITIALIZE!! */
	Py_Initialize();

	/* FROM 1 VALUE TO 2 */
	std::vector<double> x(y.size());
    for(size_t i=0; i<x.size(); ++i) x.at(i) = i;

	/* PLOT */
    PyObject* xarray = get_array(x);
    PyObject* yarray = get_array(y);

    PyObject* pystring = PyString_FromString("");		//format

    PyObject* plot_args = PyTuple_New(3);
    PyTuple_SetItem(plot_args, 0, xarray);
    PyTuple_SetItem(plot_args, 1, yarray);
    PyTuple_SetItem(plot_args, 2, pystring);

	PyObject* pyplotname = PyString_FromString("matplotlib.pyplot");		//used for show
	PyObject* pymod = PyImport_Import(pyplotname);
	PyObject* res = PyObject_CallObject(	PyObject_GetAttrString(pymod, "plot"),
											plot_args);

    Py_DECREF(plot_args);
    if(res) Py_DECREF(res);




	/* SHOW */
	PyObject* res2 = PyObject_CallObject(	PyObject_GetAttrString(pymod, "show"),
											PyTuple_New(0));
	Py_DECREF(pyplotname);
	Py_DECREF(pymod);
    Py_DECREF(res2);

		




		/* plt::plot(thetaError); */
		/* plt::show(); */
	/* terminate(); */
}

void	LinearRegression::linearRegression()
{
	int		size = price_.size();
	vector<double>	thetaError;

	thetaError.reserve(CYCLES);
	for(int j = 0; j < CYCLES; j++){
		double tmpT0 = 0;
		double tmpT1 = 0;
		for (int i = 0; i < size; i++){
			double estimatePrice = theta0_ + (theta1_ * mileage_[i]);
			double error = estimatePrice - price_[i];
			tmpT0 += error;
			tmpT1 += error * mileage_[i];
		}
		if (flags_ & 1){
			thetaError.emplace_back(tmpT0);
		}
		theta0_ -= learningRate_ * 1/size * tmpT0;
		theta1_ -= learningRate_ * 1/size * tmpT1;
	}
	if (flags_ & 1){
		write(1, "&", 1);
		/* plotThetaError(thetaError); */
		thread plotThread(plotThetaError, thetaError);
		plotThread.join();
		/* delete plotThread; */
	}

	/* plt::plot(mileage_, price_, "o"); */
	/* plt::show(); */
	createOutFile();
}
