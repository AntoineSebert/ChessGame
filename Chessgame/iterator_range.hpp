/*
	@author Antoine "Anthony" Sébert
	@creation_date 19/11/2017
	@description range of iterators
*/

#pragma once

#include <iterator>

template<typename T> struct iterator_range {
	// attributes
		private:
			T::iterator first;
			T::iterator second;

	// membres
		public:
			iterator_range(T::iterator newFirst, T::iterator newSecond) : first(newFirst), second(newSecond);
			T::iterator first();
			T::iterator second();
};