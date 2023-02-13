//
// Created by Новиков Александр Владимирович on 13.02.2023.
//

#pragma once

#include <memory>

class ITemplateClass
{
public:
	ITemplateClass() = default;
	virtual ~ITemplateClass() = default;
	virtual int process(int a, int b) = 0;
};
