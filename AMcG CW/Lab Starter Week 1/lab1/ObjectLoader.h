#pragma once
#include <string>

#include "Model.h"

class ObjectLoader
{
public:
	static Model LoadObj(const std::string& filepath);
};
