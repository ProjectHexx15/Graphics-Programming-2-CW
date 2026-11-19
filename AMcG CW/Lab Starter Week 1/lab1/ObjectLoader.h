#pragma once
#include <string>

#include "Model.h"
#include "obj_loader.h"

class ObjectLoader
{
public:
	static Model LoadObj(const std::string& filepath);
};
