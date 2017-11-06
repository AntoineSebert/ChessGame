#pragma once

/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description thread-safe templated singleton class using magic statics
*/

template<typename T> class Singleton {
	public:
		static T& getInstance();
	/*
	private:
		// construct/destruct
			T() = default;
			T(const T&) = delete;
			T(T&&) = delete;
			~T() = default;
		// assign
			T& operator=(const T&) = delete;
			T& operator=(T&&) = delete;
	*/
};

template<typename T> inline T& Singleton<T>::getInstance() {
	static T instance;
	return instance;
}