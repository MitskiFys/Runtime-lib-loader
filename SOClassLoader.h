//
// Created by Новиков Александр Владимирович on 13.02.2023.
//

#pragma once
#include <string>
#include <memory>
#include <dlfcn.h>

template <class T>
class SOClassLoader
{
public:

	explicit SOClassLoader(std::string pathToLib):
			m_pathToLib(std::move(pathToLib))
	{

	}

	~SOClassLoader() = default;

	void DLOpenLib()
	{
		if (!(m_handle = dlopen(m_pathToLib.c_str(), RTLD_NOW | RTLD_LAZY)))
		{
			std::cerr << dlerror() << std::endl;
		}
	}

	std::shared_ptr<T> getInstance()
	{
		using allocClass = T *(*)();
		using deleteClass = void (*)(T *);

		auto allocFunc = reinterpret_cast<allocClass>( dlsym(m_handle, m_allocFunc.c_str()));
		auto deleteFunc = reinterpret_cast<deleteClass>(dlsym(m_handle, m_deleteFunc.c_str()));

		if (!allocFunc || !deleteFunc)
		{
			SOCloseLib();
			std::cout << dlerror() << std::endl;
		}

		return std::shared_ptr<T>(allocFunc(), [deleteFunc](T *p){ deleteFunc(p); });
	}

	void SOCloseLib()
	{
		if (dlclose(m_handle) != 0)
		{
			std::cerr << dlerror() << std::endl;
		}
	}

private:

	void* m_handle = nullptr;
	std::string m_pathToLib;
	std::string m_allocFunc = "allocator";
	std::string m_deleteFunc = "deleter";
};
