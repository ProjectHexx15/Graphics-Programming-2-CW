#include "ObjectLoader.h"


Model ObjectLoader::LoadObj(const std::string& filepath)
{
	OBJModel obj(filepath);

	IndexedModel indexedModel = obj.ToIndexedModel();

	Model model;

	model.AddMesh(std::make_shared<Mesh>(indexedModel));

	return model;
}

