#include "Label.h"

using namespace std;
using namespace sf;

namespace UI
{
	Label::Label(): text()
	{
		
	}

	void Label::setText(wstring text) 
	{
		this->text.setString(text);
		updatePivot();
	}
	wstring Label::getText()
	{
		return text.getString();
	}

	void Label::setFillColor(Color fillColor)
	{
		UIObject::setFillColor(fillColor);
		text.setFillColor(fillColor);
	}
	Color Label::getFillColor()
	{
		return text.getFillColor();
	}

	void Label::setOutlineColor(Color outlineColor)
	{
		UIObject::setOutlineColor(outlineColor);
		text.setOutlineColor(outlineColor);
	}
	Color Label::getOutlineColor()
	{
		return text.getOutlineColor();
	}

	void Label::setOutlineThickness(float thickness)
	{
		UIObject::setOutlineThickness(thickness);
		text.setOutlineThickness(thickness);
	}
	float Label::getOutlineThickness() 
	{
		return text.getOutlineThickness();
	}

	void Label::setFont(Font & font)
	{
		text.setFont(font);
	}
	const Font * Label::getFont()
	{
		return text.getFont();
	}

	void Label::setFontSize(unsigned int fontSize)
	{
		text.setCharacterSize(fontSize);
	}
	unsigned int Label::getFontSize()
	{
		return text.getCharacterSize();
	}


	void Label::setGlobalPosition(Vector2f position) 
	{
		UIObject::setGlobalPosition(position);

		text.setPosition(position);
	}

	void Label::draw()
	{
		UIObject::draw();
		
		getWindow()->draw(text);
	}
	void Label::updatePivot()
	{
		UIObject::updatePivot();

		FloatRect rect = text.getLocalBounds();
		text.setOrigin(Vector2f(rect.width * getPivot().x,
			rect.height * getPivot().y));
	}

	Label::~Label()
	{
	}
}
