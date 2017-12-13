/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description thread-safe templated singleton class using magic statics
*/

#pragma once

template<typename T> class Singleton {
	public:
		static T& getInstance() {
			static T instance;
			return instance;
		}
};