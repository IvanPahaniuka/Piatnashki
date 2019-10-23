#include "Table.h"


namespace UI 
{
	Table::Table()
	{
		UI::Rect::setFillColor(Color::Transparent);
	}

	void Table::setWindow(RenderWindow & window)
	{
		UI::Rect::setWindow(window);

		for (int i = 0; i < getVRectCount(); i++)
			vrects[i].setWindow(window);

		for (int i = 0; i < getHRectCount(); i++)
			hrects[i].setWindow(window);
	}

	void Table::setSize(Vector2f size)
	{
		UI::Rect::setSize(size);

		updateModel();
	}

	void Table::setCellsCount(Vector2u cellsCount)
	{
		this->cellsCount = cellsCount;

		updateModel();
	}

	Vector2u Table::getCellsCount()
	{
		return cellsCount;
	}

	void Table::setOutlineColor(Color outlineColor)
	{
		UI::Rect::setOutlineColor(outlineColor);

		for (int i = 0; i < getVRectCount(); i++)
			vrects[i].setOutlineColor(outlineColor);

		for (int i = 0; i < getHRectCount(); i++)
			hrects[i].setOutlineColor(outlineColor);
	}

	void Table::setOutlineThickness(float thickness)
	{
		UI::Rect::setOutlineThickness(thickness);

		for (int i = 0; i < getVRectCount(); i++)
			vrects[i].setOutlineThickness(thickness);

		for (int i = 0; i < getHRectCount(); i++)
			hrects[i].setOutlineThickness(thickness);
	}

	Table::~Table()
	{
	}

	void Table::draw()
	{
		for (int i = 0; i < getVRectCount(); i++)
			vrects[i].render();

		UI::Rect::draw();

		for (int i = 0; i < getHRectCount(); i++)
			hrects[i].render();
	}

	void Table::updateModel()
	{
		updateHModel();
		updateVModel();
	}

	void Table::updateHModel()
	{
		delete[] hrects;
		hrects = new UI::Rect[getHRectCount()];

		float dl = (getSize().y + getOutlineThickness()) / getCellsCount().y;
		Vector2f size = Vector2f(getSize().x, dl - getOutlineThickness());
		Vector2f startPos = Vector2f(0, -getSize().y / 2 + dl);
		for (int i = 0; i < getHRectCount(); i++)
		{
			hrects[i].setWindow(*getWindow());
			hrects[i].setParent(this);
			hrects[i].setPivot(Vector2f(0.5, 0));
			hrects[i].setFillColor(Color::Transparent);
			hrects[i].setOutlineColor(getOutlineColor());
			hrects[i].setOutlineThickness(getOutlineThickness());
			hrects[i].setSize(size);
			hrects[i].setLocalPosition(Vector2f(startPos.x, startPos.y + dl * i * 2));
		}
	}

	void Table::updateVModel()
	{
		delete[] vrects;
		vrects = new UI::Rect[getVRectCount()];

		float dl = (getSize().x + getOutlineThickness()) / getCellsCount().x;
		Vector2f size = Vector2f(dl - getOutlineThickness(), getSize().y);
		Vector2f startPos = Vector2f(-getSize().x / 2 + dl, 0);
		for (int i = 0; i < getVRectCount(); i++)
		{
			vrects[i].setWindow(*getWindow());
			vrects[i].setParent(this);
			vrects[i].setPivot(Vector2f(0, 0.5));
			vrects[i].setFillColor(Color::Transparent);
			vrects[i].setOutlineColor(getOutlineColor());
			vrects[i].setOutlineThickness(getOutlineThickness());
			vrects[i].setSize(size);
			vrects[i].setLocalPosition(Vector2f(startPos.x + dl * i * 2, startPos.y));
		}
	}

	unsigned int Table::getVRectCount()
	{
		return cellsCount.x / 2;
	}

	unsigned int Table::getHRectCount()
	{
		return cellsCount.y / 2;
	}
}
