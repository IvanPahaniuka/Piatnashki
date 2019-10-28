#include "ButtonsTable.h"


namespace UI 
{
	ButtonsTable::ButtonsTable()
	{
	}

	void ButtonsTable::setWindow(RenderWindow & window)
	{
		Table::setWindow(window);

		for (int i = 0; i < getCellsCount().x * getCellsCount().y; i++)
			buttons[i].setWindow(window);
	}

	void ButtonsTable::setText(wstring text)
	{
		this->text = text;

		updateText();
	}

	wstring ButtonsTable::getText()
	{
		return text;
	}

	void ButtonsTable::setFont(Font & font)
	{
		this->font = &font;

		for (int i = 0; i < getCellsCount().x*getCellsCount().y; i++)
			buttons[i].setFont(font);
	}

	Font * ButtonsTable::getFont()
	{
		return font;
	}

	void ButtonsTable::setFontSize(unsigned int fontSize)
	{
		this->fontSize = fontSize;

		for (int i = 0; i < getCellsCount().x*getCellsCount().y; i++)
			buttons[i].setFontSize(fontSize);
	}

	unsigned int ButtonsTable::getFontSize()
	{
		return fontSize;
	}

	void ButtonsTable::setFillColor(Color color)
	{
		fillColor = color;

		for (int i = 0; i < getCellsCount().x*getCellsCount().y; i++)
			buttons[i].setFillColor(color);
	}

	Color ButtonsTable::getFillColor()
	{
		return fillColor;
	}

	Vector2i ButtonsTable::getCellByObject(UIObject * obj)
	{
		for (int i = 0; i < getCellsCount().y; i++)
			for (int j = 0; j < getCellsCount().x; j++)
				if (&buttons[i*getCellsCount().x + j] == obj)
					return Vector2i(j, i);

		return Vector2i(-1, -1);

	}

	void ButtonsTable::setNormalState(ButtonStateFunc onNormal)
	{
		onNormalState = onNormal;

		for (int i = 0; i < getCellsCount().x*getCellsCount().y; i++)
			buttons[i].setNormalState(onNormal);
	}

	void ButtonsTable::setOverState(ButtonStateFunc onOver)
	{
		onOverState = onOver;

		for (int i = 0; i < getCellsCount().x*getCellsCount().y; i++)
			buttons[i].setOverState(onOver);
	}

	void ButtonsTable::setPressedState(ButtonStateFunc onPressed)
	{
		onPressedState = onPressed;

		for (int i = 0; i < getCellsCount().x*getCellsCount().y; i++)
			buttons[i].setPressedState(onPressed);
	}

	void ButtonsTable::setClick(ClickFunc onClick)
	{
		this->onClick = onClick;

		for (int i = 0; i < getCellsCount().x*getCellsCount().y; i++)
			buttons[i].setClick(onClick);
	}

	void ButtonsTable::update()
	{
		Table::update();

		int count = getCellsCount().x*getCellsCount().y;
		for (int i = 0; i < count; i++)
			buttons[i].update();
	}


	ButtonsTable::~ButtonsTable()
	{
	}

	void ButtonsTable::draw()
	{
		Table::draw();

		for (int i = 0; i < getCellsCount().x * getCellsCount().y; i++)
			buttons[i].render();
	}

	void ButtonsTable::updateModel()
	{
		Table::updateModel();

		updateButtonsModel();
	}

	void ButtonsTable::updateButtonsModel()
	{
		Vector2u cells = getCellsCount();
		delete[] buttons;
		buttons = new LabelButton[cells.y*cells.x];


		Vector2f dl = Vector2f((getSize().x + getOutlineThickness()) / cells.x,
			(getSize().y + getOutlineThickness()) / cells.y);
		Vector2f startPos = Vector2f((dl.x - getSize().x - getOutlineThickness()) / 2,
			(dl.y - getSize().y - getOutlineThickness()) / 2);

		for (int i = 0; i < cells.y; i++)
			for (int j = 0; j < cells.x; j++)
			{
				int index = i * cells.x + j;
				buttons[index].setWindow(*getWindow());
				buttons[index].setParent(this);
				buttons[index].setFont(*font);
				buttons[index].setFontSize(fontSize);
				buttons[index].setLocalPosition(startPos + Vector2f(dl.x*j, dl.y*i));
				buttons[index].setFillColor(fillColor);
				buttons[index].setPivot(Vector2f(0.5, 0.5));
				buttons[index].setSize(dl);

				buttons[index].setNormalState(onNormalState);
				buttons[index].setOverState(onOverState);
				buttons[index].setPressedState(onPressedState);
				buttons[index].setClick(onClick);
			}


		updateText();
	}

	void ButtonsTable::updateText()
	{
		for (int i = 0; i < getCellsCount().x*getCellsCount().y; i++)
		{
			if (i < text.length())
				buttons[i].setText(wstring(&text[i], 1));
			else
				buttons[i].setText(L"");
		}
	}
}