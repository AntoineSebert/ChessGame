#include "Singleton.h"

/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description thread-safe templated singleton class using magic statics
*/

template<typename T> inline T & Singleton<T>::getInstance() {
	static T instance;
	return instance;
}