#include "Object.h"


Object::Object()
{

}

Vector2f Object::getLocalPosition() 
{
	if (parent != nullptr)
		return position - parent->getGlobalPosition();
	else
		return position;
}

void Object::setLocalPosition(Vector2f localPosition)
{
	if (parent != nullptr)
		setGlobalPosition(parent->getGlobalPosition() + localPosition);
	else
		setGlobalPosition(localPosition);
}

Vector2f Object::getGlobalPosition() 
{
	return position;
}

void Object::setGlobalPosition(Vector2f position)
{
	Vector2f dl = position - this->position;

	this->position = position;
	
	for (Object* child : childs)
		child->setGlobalPosition(child->getGlobalPosition() + dl);
}

void Object::setActive(bool active) 
{
	isActive = active;

	for (Object* child: childs)
		child->setActive(active);
}

bool Object::getActive() 
{
	return isActive;
}

void Object::setParent(Object* obj)
{
	if (parent != obj)
	{
		if (parent != NULL)
			if (parent->containsChild(*this))
				parent->removeChild(*this);

		parent = obj;

		if (parent != NULL)
		{
			if (!parent->containsChild(*this))
				parent->addChild(*this);

			setActive(parent->getActive());
		}
	}
}

Object* Object::getParent()
{
	return parent;
}

void Object::addChild(Object &obj) 
{
	childs.push_front(&obj);
	obj.setParent(this);
}

bool Object::containsChild(Object &obj)
{
	for (Object* child: childs)
		if (child == &obj)
			return true;

	return false;
}

void Object::removeChild(Object &child)
{
	childs.remove(&child);
	child.parent = nullptr;
}

Object::~Object()
{
	if (this->parent != nullptr)
		this->parent->removeChild(*this);
}