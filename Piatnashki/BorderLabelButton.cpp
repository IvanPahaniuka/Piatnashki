#include "BorderLabelButton.h"


namespace UI 
{
	BorderLabelButton::BorderLabelButton()
	{
		label.setParent(this);
		label.setPivot(Vector2f(0.5, 0.5));
		label.setLocalPosition(Vector2f(0, 0));
		label.setFillColor(Color::Blue);
		label.setText(L"BUTTON");

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
		Button::setWindow(window);

		border.setWindow(window);
		label.setWindow(window);
	}

	void BorderLabelButton::setText(wstring text)
	{
		label.setText(text);
	}

	wstring BorderLabelButton::getText()
	{
		return label.getText();
	}

	void BorderLabelButton::setFont(Font & font)
	{
		label.setFont(font);
	}

	const Font * BorderLabelButton::getFont()
	{
		return label.getFont();
	}

	void BorderLabelButton::setFontSize(unsigned int fontSize)
	{
		label.setFontSize(fontSize);
	}

	unsigned int BorderLabelButton::getFontSize()
	{
		return label.getFontSize();
	}

	void BorderLabelButton::setFillColor(Color fillColor)
	{
		label.setFillColor(fillColor);
	}

	Color BorderLabelButton::getFillColor()
	{
		return label.getFillColor();
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
		Button::updateRect();

		border.setSize(getSize());

		Vector2f center = Vector2f(getBounds().left + getSize().x / 2, getBounds().top + getSize().y / 2);
		border.setGlobalPosition(center);
		label.setGlobalPosition(center);
	}

	void BorderLabelButton::draw()
	{
		Button::draw();

		border.render();
		label.render();
	}

	BorderLabelButton::~BorderLabelButton()
	{
	}
}
