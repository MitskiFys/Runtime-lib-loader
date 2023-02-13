#include <iostream>
#include "SOClassLoader.h"
#include "ITemplateClass.h"

constexpr const auto ProjectSource_ = "/home/mitski/Develop/SharedClass/";

int main()
{
	SOClassLoader<ITemplateClass> loaderClass(std::string(ProjectSource_).append("lib/libSumClass.so"));
	loaderClass.DLOpenLib();
	{
		std::shared_ptr<ITemplateClass> sumClass = loaderClass.getInstance();
		std::cout << sumClass->process(5,6) << std::endl;
	}
	loaderClass.SOCloseLib();
	return 0;
}
