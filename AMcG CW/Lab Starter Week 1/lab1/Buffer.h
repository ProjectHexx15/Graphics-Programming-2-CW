#pragma once

#include <GL/glew.h>

class VertexBufferObject
{
private:
	unsigned int id = 0;

public:
	VertexBufferObject(const void* data, size_t size);
	~VertexBufferObject();

	void Bind() const;
	void UnBind() const;

	unsigned int GetID() const { return id; }


};

class VertexArrayObject
{
public:
	VertexArrayObject();
	~VertexArrayObject();

	void Bind() const;
	void UnBind();

	unsigned int GetID() const { return id; }

	void AddAttribute(unsigned int layout, int size, unsigned int type, unsigned int bindingIndex, unsigned int offset);
	void BindVertexBuffer(unsigned int bindingIndex, const VertexBufferObject& vbo, unsigned int stride, unsigned int long long offset = 0);
	void BindIndexBuffer(const IndexBufferObject& ebo);

private:
	unsigned int id = 0;
};

class IndexBufferObject
{
public:
	IndexBufferObject(const unsigned int* indices, unsigned int count);
	~IndexBufferObject();

	void Bind() const;
	void UnBind() const;

	unsigned int GetCount() const { return count; }
	unsigned int GetID() const { return id; }

private:
	unsigned int id = 0;
	unsigned int count = 0;

};
