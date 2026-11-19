#include "Buffer.h"	

#include <GL/glew.h>

VertexBufferObject::VertexBufferObject(const void* data, size_t size)
{
	glCreateBuffers(1, &id);
	glNamedBufferData(id, size, data, GL_STATIC_DRAW);

}
VertexBufferObject::~VertexBufferObject()
{
	if (id)
	{
		glDeleteBuffers(1, &id);
	}
	
}

void VertexBufferObject::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
}
void VertexBufferObject::UnBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

IndexBufferObject::IndexBufferObject(const unsigned int* indices, unsigned int count): count(count)
{
	glCreateBuffers(1, &id);

	glNamedBufferData(id, count * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}

IndexBufferObject::~IndexBufferObject()
{
	if (id)
	{
		glDeleteBuffers(1, &id);
	}
}

void IndexBufferObject::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void IndexBufferObject::UnBind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

VertexArrayObject::VertexArrayObject()
{
	glCreateVertexArrays(1, &id);
}

VertexArrayObject::~VertexArrayObject()
{
	if (id)
	{
		glDeleteVertexArrays(1, &id);
	}
}

void VertexArrayObject::Bind() const
{
	glBindVertexArray(id);
}

void VertexArrayObject::UnBind()
{
	glBindVertexArray(0);
}

void VertexArrayObject::AddAttribute(unsigned int layout, int size, unsigned int type, unsigned int bindingIndex, unsigned int offset)
{
	glEnableVertexArrayAttrib(id, layout);
	glVertexArrayAttribFormat(id, layout, size, type, GL_FALSE, offset);

	glVertexArrayAttribBinding(id, layout, bindingIndex);

}

void VertexArrayObject::BindVertexBuffer(unsigned int bindingIndex, const VertexBufferObject& vbo, unsigned int stride, unsigned long long offset)
{
	glVertexArrayVertexBuffer(id, bindingIndex, vbo.GetID(), offset, stride);
}

void VertexArrayObject::BindIndexBuffer(const IndexBufferObject& ebo)
{
	glVertexArrayElementBuffer(id, ebo.GetID());
}