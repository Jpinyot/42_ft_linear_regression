/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 09:00:12 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/15 12:32:15 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <map>

#include <Python.h>
#include <numpy/arrayobject.h>

using namespace std;

class Plot{
	private:
		PyObject*	getArray(const vector<double>& array);

	public:
		Plot(){
			Py_Initialize();
			if(PyArray_API == NULL){
			    import_array();
			}
		};
		void	plot(const vector<double>& y, const string format="");
		void	plot(const vector<double>& x, const vector<double>& y, const string format="");
		void	named_plot(const string& name, const vector<double>& y, const string& format = "");
		void	named_plot(const string& name, const vector<double>& x, const vector<double>& y, const string& format = "");
		void	subplot(long nRows, long nCols, long plotNumber);
		void	subplot2grid(long nRows, long nCols, long rowId=0, long colId=0, long rowSpan=1, long colSpan=1);
		void	axis(const std::string &axisstr);
		void	ylim(double left, double right);
		void	xlim(double left, double right);
		void	tick_params(const map<string, string>& keywords, const string axis = "both");
		void	legend();
		void	show();
};
