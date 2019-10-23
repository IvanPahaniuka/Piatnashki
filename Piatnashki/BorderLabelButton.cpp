#include "BorderLabelButton.h"


namespace UI 
{
	BorderLabelButton::BorderLabelButton()
	{
		border.setParent(this);
		border.setPivot(Vector2f(0.5, 0.5));
		border.setLocalPosition(Vector2f(0, 0));
		border.setSize(getSize());
		border.setFillColor(Color::Transparent);
		border.setOutlineThickness(5);
		border.setOutlineColor(Color::Blue);
	}

	void BorderLabelButton::setWindow(RenderWindow & window)
	{
		LabelButton::setWindow(window);

		border.setWindow(window);
	}

	void BorderLabelButton::setOutlineColor(Color outlineColor)
	{
		border.setOutlineColor(outlineColor);
	}

	Color BorderLabelButton::getOutlineColor()
	{
		return border.getOutlineColor();
	}

	void BorderLabelButton::setOutlineThickness(float thickness)
	{
		border.setOutlineThickness(thickness);
	}

	float BorderLabelButton::getOutlineThickness()
	{
		return border.getOutlineThickness();
	}

	void BorderLabelButton::updateRect()
	{
		LabelButton::updateRect();

		border.setSize(getSize());

		Vector2f center = Vector2f(getBounds().left + getSize().x / 2, getBounds().top + getSize().y / 2);
		border.setGlobalPosition(center);
	}

	void BorderLabelButton::draw()
	{
		LabelButton::draw();

		border.render();
	}

	BorderLabelButton::~BorderLabelButton()
	{
	}
}
