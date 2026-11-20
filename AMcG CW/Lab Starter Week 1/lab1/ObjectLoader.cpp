#include "ObjectLoader.h"

// loads object assets and creates models for the engine

Model ObjectLoader::LoadObj(const std::string& filepath)
{
	OBJModel obj(filepath);

	IndexedModel indexedModel = obj.ToIndexedModel();

	Model model;

	model.AddMesh(std::make_shared<Mesh>(indexedModel));

	return model;
}

