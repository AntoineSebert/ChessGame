#include "Singleton.h"

/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description thread-safe templated singleton class using magic statics
*/

template<typename T> T& Singleton::GetInstance() {
	static T instance;
	return instance;
}