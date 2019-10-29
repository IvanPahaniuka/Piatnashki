#include "StringTable.h"

using namespace std;

namespace UI 
{
	StringTable::StringTable()
	{
	}

	void StringTable::setWindow(RenderWindow & window)
	{
		Table::setWindow(window);

		for (int i = 0; i < getCellsCount().x * getCellsCount().y; i++)
			labels[i].setWindow(window);
	}



	void StringTable::setText(wstring *text, int count)
	{
		delete[] this->text;

		this->text = text;
		textCount = count;

		updateText();
	}

	wstring *StringTable::getText()
	{
		return text;
	}

	void StringTable::setFont(Font & font)
	{
		this->font = &font;

		for (int i = 0; i < getCellsCount().x*getCellsCount().y; i++)
			labels[i].setFont(font);
	}

	Font * StringTable::getFont()
	{
		return font;
	}

	void StringTable::setFontSize(unsigned int fontSize)
	{
		this->fontSize = fontSize;

		for (int i = 0; i < getCellsCount().x*getCellsCount().y; i++)
			labels[i].setFontSize(fontSize);
	}

	unsigned int StringTable::getFontSize()
	{
		return fontSize;
	}

	void StringTable::setFillColor(Color color)
	{
		fillColor = color;

		for (int i = 0; i < getCellsCount().x*getCellsCount().y; i++)
			labels[i].setFillColor(color);
	}

	Color StringTable::getFillColor()
	{
		return fillColor;
	}


	StringTable::~StringTable()
	{

	}

	void StringTable::draw()
	{
		Table::draw();

		for (int i = 0; i < getCellsCount().x * getCellsCount().y; i++)
			labels[i].render();
	}

	void StringTable::updateModel()
	{
		Table::updateModel();

		updateLabelsModel();
	}

	void StringTable::updateLabelsModel()
	{
		delete[] labels;

		labels = new Label[getCellsCount().x*getCellsCount().y];

		Vector2f dl = Vector2f((getSize().x + getOutlineThickness()) / getCellsCount().x, 
			(getSize().y + getOutlineThickness()) / getCellsCount().y);
		Vector2f startPos = Vector2f((dl.x - getSize().x - getOutlineThickness()) / 2, 
			(dl.y - getSize().y - getOutlineThickness()) / 2) ;

		for (int i = 0; i < getCellsCount().y; i++)
			for (int j = 0; j < getCellsCount().x; j++) 
			{
				int index = i * getCellsCount().x + j;
				labels[index].setWindow(*getWindow());
				labels[index].setParent(this);
				labels[index].setFont(*font);
				labels[index].setFontSize(fontSize);
				labels[index].setLocalPosition(startPos + Vector2f(dl.x*j, dl.y*i));
				labels[index].setFillColor(fillColor);
				labels[index].setPivot(Vector2f(0.5, 0.5));
			}


		updateText();
	}

	void StringTable::updateText()
	{
		for (int i = 0; i < getCellsCount().x*getCellsCount().y; i++)
		{
			if (i < textCount)
				labels[i].setText(text[i]);
			else
				labels[i].setText(L"");

			
		}
	}
}
