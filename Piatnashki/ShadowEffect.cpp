#include "ShadowEffect.h"

using namespace std;
using namespace sf;

namespace UI
{
	ShadowEffect::ShadowEffect()
	{
	}

	ShadowEffect::ShadowEffect(UIObject &target) : Effect(target)
	{

	}

	void ShadowEffect::draw()
	{
		Color fillColor = getTarget()->getFillColor();
		Color outlineColor = getTarget()->getOutlineColor();
		Vector2f position = getTarget()->getGlobalPosition();

		Color shColor = Color::Color(color.r, color.g, color.b, getTarget()->getFillColor().a);
		getTarget()->setFillColor(shColor);
		shColor = Color::Color(color.r, color.g, color.b, getTarget()->getOutlineColor().a);
		getTarget()->setOutlineColor(shColor);
		getTarget()->setGlobalPosition(getTarget()->getGlobalPosition() + offset);
		drawTarget();

		getTarget()->setFillColor(fillColor);
		getTarget()->setOutlineColor(outlineColor);
		getTarget()->setGlobalPosition(position);
	}

	void ShadowEffect::setColor(Color color)
	{
		this->color = color;
	}

	Color ShadowEffect::getColor()
	{
		return color;
	}

	void ShadowEffect::setOffset(Vector2f offset)
	{
		this->offset = offset;
	}

	Vector2f ShadowEffect::getOffset()
	{
		return offset;
	}

	ShadowEffect::~ShadowEffect()
	{
	}
}
