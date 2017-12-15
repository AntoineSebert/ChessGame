/**
	\author Antoine "Anthony" Sébert
	\date 04/11/2017
	\brief thread-safe templated singleton class using magic statics
*/

#pragma once

template<typename T> class Singleton {
	public:
		static T& getInstance() {
			static T instance;
			return instance;
		}
};