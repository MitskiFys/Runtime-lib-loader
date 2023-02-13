//
// Created by Новиков Александр Владимирович on 13.02.2023.
//

#pragma once
#include "ITemplateClass.h"

class Sum : public ITemplateClass
{
public:

	Sum() = default;
	int process(int a, int b) override;
	~Sum() override = default;
};