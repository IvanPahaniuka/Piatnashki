#include "CharsTable.h"

using namespace std;

namespace UI 
{
	CharsTable::CharsTable()
	{
	}

	void CharsTable::setWindow(RenderWindow & window)
	{
		Table::setWindow(window);

		for (int i = 0; i < getCellsCount().x * getCellsCount().y; i++)
			labels[i].setWindow(window);
	}

	void CharsTable::setText(wstring text)
	{
		this->text = text;

		updateText();
	}

	wstring CharsTable::getText()
	{
		return text;
	}

	void CharsTable::setFont(Font & font)
	{
		this->font = &font;

		for (int i = 0; i < getCellsCount().x*getCellsCount().y; i++)
			labels[i].setFont(font);
	}

	Font * CharsTable::getFont()
	{
		return font;
	}

	void CharsTable::setFontSize(unsigned int fontSize)
	{
		this->fontSize = fontSize;

		for (int i = 0; i < getCellsCount().x*getCellsCount().y; i++)
			labels[i].setFontSize(fontSize);
	}

	unsigned int CharsTable::getFontSize()
	{
		return fontSize;
	}

	void CharsTable::setFillColor(Color color)
	{
		fillColor = color;

		for (int i = 0; i < getCellsCount().x*getCellsCount().y; i++)
			labels[i].setFillColor(color);
	}

	Color CharsTable::getFillColor()
	{
		return fillColor;
	}


	CharsTable::~CharsTable()
	{

	}

	void CharsTable::draw()
	{
		Table::draw();

		for (int i = 0; i < getCellsCount().x * getCellsCount().y; i++)
			labels[i].render();
	}

	void CharsTable::updateModel()
	{
		Table::updateModel();

		updateLabelsModel();
	}

	void CharsTable::updateLabelsModel()
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

	void CharsTable::updateText()
	{
		for (int i = 0; i < getCellsCount().x*getCellsCount().y; i++)
		{
			if (i < text.length())
				labels[i].setText(wstring(&text[i], 1));
			else
				labels[i].setText(L"");

			
		}
	}
}
