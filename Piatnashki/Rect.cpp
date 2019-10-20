#include "Rect.h"

using namespace std;
using namespace sf;

namespace UI 
{
	Rect::Rect()
	{
	}

	void Rect::setSize(Vector2f size)
	{
		rect.setSize(size);

		updatePivot();
	}

	Vector2f Rect::getSize()
	{
		return rect.getSize();
	}

	void Rect::setGlobalPosition(Vector2f position)
	{
		UIObject::setGlobalPosition(position);

		rect.setPosition(position);
	}

	void Rect::setFillColor(Color fillColor)
	{
		UIObject::setFillColor(fillColor);

		rect.setFillColor(fillColor);
	}

	Color Rect::getFillColor()
	{
		return rect.getFillColor();
	}

	void Rect::setOutlineColor(Color outlineColor)
	{
		UIObject::setOutlineColor(outlineColor);

		rect.setOutlineColor(outlineColor);
	}

	Color Rect::getOutlineColor()
	{
		return rect.getOutlineColor();
	}

	void Rect::setOutlineThickness(float thickness)
	{
		UIObject::setOutlineThickness(thickness);

		rect.setOutlineThickness(thickness);
	}

	float Rect::getOutlineThickness()
	{
		return rect.getOutlineThickness();
	}


	Rect::~Rect()
	{
	}

	void Rect::updatePivot()
	{
		UIObject::updatePivot();

		rect.setOrigin(Vector2f(getSize().x * getPivot().x,
			getSize().y * getPivot().y));
	}

	void Rect::draw()
	{
		UIObject::draw();

		getWindow()->draw(rect);
	}
}
