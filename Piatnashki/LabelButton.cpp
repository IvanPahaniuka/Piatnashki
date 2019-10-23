#include "LabelButton.h"


namespace UI 
{
	LabelButton::LabelButton()
	{
		label.setParent(this);
		label.setPivot(Vector2f(0.5, 0.5));
		label.setLocalPosition(Vector2f(0, 0));
		label.setFillColor(Color::Blue);
		label.setText(L"BUTTON");
	}

	void LabelButton::setWindow(RenderWindow & window)
	{
		Button::setWindow(window);

		label.setWindow(window);
	}

	void LabelButton::setText(wstring text)
	{
		label.setText(text);
	}

	wstring LabelButton::getText()
	{
		return label.getText();
	}

	void LabelButton::setFont(Font & font)
	{
		label.setFont(font);
	}

	const Font * LabelButton::getFont()
	{
		return label.getFont();
	}

	void LabelButton::setFontSize(unsigned int fontSize)
	{
		label.setFontSize(fontSize);
	}

	unsigned int LabelButton::getFontSize()
	{
		return label.getFontSize();
	}

	void LabelButton::setFillColor(Color fillColor)
	{
		label.setFillColor(fillColor);
	}

	Color LabelButton::getFillColor()
	{
		return label.getFillColor();
	}

	void LabelButton::setOutlineColor(Color outlineColor)
	{
		label.setOutlineColor(outlineColor);
	}

	Color LabelButton::getOutlineColor()
	{
		return label.getOutlineColor();
	}

	void LabelButton::setOutlineThickness(float thickness)
	{
		label.setOutlineThickness(thickness);
	}

	float LabelButton::getOutlineThickness()
	{
		return label.getOutlineThickness();
	}


	LabelButton::~LabelButton()
	{
	}

	void LabelButton::updateRect()
	{
		Button::updateRect();

		Vector2f center = Vector2f(getBounds().left + getSize().x / 2, getBounds().top + getSize().y / 2);
		label.setGlobalPosition(center);
	}

	void LabelButton::draw()
	{
		Button::draw();

		label.render();
	}
}
