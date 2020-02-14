/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 09:00:03 by jpinyot           #+#    #+#             */
/*   Updated: 2020/02/14 12:26:41 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plot.h"

PyObject* Plot::getArray(const vector<double>& array)
{
    npy_intp dims = array.size();
	void* value = (void*)array.data();
	PyObject* retArray = PyArray_SimpleNewFromData(1, &dims, NPY_DOUBLE, value);
    return retArray;
}

void	Plot::plot(const vector<double>& y, const string format)
{
			Py_Initialize();			//revisar!!!!
			if(PyArray_API == NULL){
			    import_array();
			}
	/* FROM 1 VALUE TO 2 */
	std::vector<double> x(y.size());
    for(size_t i=0; i<x.size(); ++i) x.at(i) = i;

    PyObject* xarray = getArray(x);
    PyObject* yarray = getArray(y);

    PyObject* pystring = PyString_FromString(format.c_str());		//format

    PyObject* plot_args = PyTuple_New(3);
    PyTuple_SetItem(plot_args, 0, xarray);
    PyTuple_SetItem(plot_args, 1, yarray);
    PyTuple_SetItem(plot_args, 2, pystring);

	PyObject* pyplotname = PyString_FromString("matplotlib.pyplot");
	PyObject* pymod = PyImport_Import(pyplotname);
	PyObject* res = PyObject_CallObject(	PyObject_GetAttrString(pymod, "plot"),
											plot_args);

    Py_DECREF(plot_args);
	Py_DECREF(pyplotname);
	Py_DECREF(pymod);
    if(res) Py_DECREF(res);
}

void	Plot::plot(const vector<double>& x, const vector<double>& y, const string format)
{
    PyObject* xarray = getArray(x);
    PyObject* yarray = getArray(y);

    PyObject* pystring = PyString_FromString(format.c_str());		//format

    PyObject* plot_args = PyTuple_New(3);
    PyTuple_SetItem(plot_args, 0, xarray);
    PyTuple_SetItem(plot_args, 1, yarray);
    PyTuple_SetItem(plot_args, 2, pystring);

	PyObject* pyplotname = PyString_FromString("matplotlib.pyplot");
	PyObject* pymod = PyImport_Import(pyplotname);
	PyObject* res = PyObject_CallObject(	PyObject_GetAttrString(pymod, "plot"),
											plot_args);

    Py_DECREF(plot_args);
	Py_DECREF(pyplotname);
	Py_DECREF(pymod);
    if(res) Py_DECREF(res);
}

void	Plot::subplot(long nRows, long nCols, long plotNumber)
{
	PyObject* pyplotname = PyString_FromString("matplotlib.pyplot");
	PyObject* pymod = PyImport_Import(pyplotname);

    PyObject* args = PyTuple_New(3);
    PyTuple_SetItem(args, 0, PyFloat_FromDouble(nRows));
    PyTuple_SetItem(args, 1, PyFloat_FromDouble(nCols));
    PyTuple_SetItem(args, 2, PyFloat_FromDouble(plotNumber));

	PyObject* res = PyObject_CallObject(	PyObject_GetAttrString(pymod, "subplot"),
											args);
    if(!res) throw std::runtime_error("Call to subplot() failed.");

	Py_DECREF(pyplotname);
	Py_DECREF(pymod);

    Py_DECREF(args);
    Py_DECREF(res);
}

void	Plot::subplot2grid(long nRows, long nCols, long rowId, long colId, long rowSpan, long colSpan)
{
	PyObject* pyplotname = PyString_FromString("matplotlib.pyplot");
	PyObject* pymod = PyImport_Import(pyplotname);

    PyObject* shape = PyTuple_New(2);
    PyTuple_SetItem(shape, 0, PyLong_FromLong(nRows));
    PyTuple_SetItem(shape, 1, PyLong_FromLong(nCols));

    PyObject* loc = PyTuple_New(2);
    PyTuple_SetItem(loc, 0, PyLong_FromLong(rowId));
    PyTuple_SetItem(loc, 1, PyLong_FromLong(colId));

    PyObject* args = PyTuple_New(4);
    PyTuple_SetItem(args, 0, shape);
    PyTuple_SetItem(args, 1, loc);
    PyTuple_SetItem(args, 2, PyLong_FromLong(rowSpan));
    PyTuple_SetItem(args, 3, PyLong_FromLong(colSpan));

	PyObject* res = PyObject_CallObject(	PyObject_GetAttrString(pymod, "subplot2grid"),
											args);
    if(!res) throw std::runtime_error("Call to subplot2grid() failed.");

	Py_DECREF(pyplotname);
	Py_DECREF(pymod);

    Py_DECREF(shape);
    Py_DECREF(loc);
    Py_DECREF(args);
    Py_DECREF(res);
	
}

void	Plot::tick_params(const map<string, string>& keywords, const string axis)
{
	PyObject* pyplotname = PyString_FromString("matplotlib.pyplot");
	PyObject* pymod = PyImport_Import(pyplotname);

	// construct positional args
	PyObject* args;
	args = PyTuple_New(1);
	PyTuple_SetItem(args, 0, PyString_FromString(axis.c_str()));
	
	// construct keyword args
	PyObject* kwargs = PyDict_New();
	for (map<string, string>::const_iterator it = keywords.begin(); it != keywords.end(); ++it){
		PyDict_SetItemString(kwargs, it->first.c_str(), PyString_FromString(it->second.c_str()));
	}

	PyObject* res = PyObject_Call(	PyObject_GetAttrString(pymod, "tick_params"),
									args, kwargs);
	/* PyObject* res = PyObject_Call(detail::_interpreter::get().s_python_function_tick_params, args, kwargs); */
  
	if (!res) throw std::runtime_error("Call to tick_params() failed");

	Py_DECREF(pyplotname);
	Py_DECREF(pymod);
  
	Py_DECREF(args);
	Py_DECREF(kwargs);
	Py_DECREF(res);
}

void	Plot::show()
{
	PyObject* pyplotname = PyString_FromString("matplotlib.pyplot");		//used for show
	PyObject* pymod = PyImport_Import(pyplotname);
	PyObject* res = PyObject_CallObject(	PyObject_GetAttrString(pymod, "show"),
											PyTuple_New(0));
	Py_DECREF(pyplotname);
	Py_DECREF(pymod);
    if(res) Py_DECREF(res);
}
