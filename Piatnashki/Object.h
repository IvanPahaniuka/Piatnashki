#pragma once
#include <SFML/Graphics.hpp>
#include <forward_list>

using namespace sf;
using namespace std;

class Object
{
public:
	Object();

	Vector2f getLocalPosition();
	void setLocalPosition(Vector2f localPosition);

	Vector2f getGlobalPosition();
	virtual void setGlobalPosition(Vector2f position);

	bool getActive();
	virtual void setActive(bool active);
	
	Object* getParent();
	virtual void setParent(Object* obj);

	void addChild(Object &obj);
	bool containsChild(Object &obj);
	void removeChild(Object &child);

	~Object();

private:
	Vector2f position = Vector2f(0, 0);
	bool isActive = true;
	Object* parent = nullptr;
	forward_list<Object*> childs;
};

