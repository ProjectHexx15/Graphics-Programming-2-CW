#pragma once
#include "ShaderLoader.h"
#include "Mesh.h"

class ResourceManager
{

private:
	ResourceManager();
	~ResourceManager();

public:
	static ResourceManager& getInstance()
	{
		static ResourceManager instance;
		return instance;
	}

};
