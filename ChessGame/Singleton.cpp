#include "Singleton.h"

template<typename T> T& Singleton::GetInstance() {
	static T instance;
	return instance;
}