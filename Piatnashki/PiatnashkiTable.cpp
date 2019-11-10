#include "PiatnashkiTable.h"


namespace UI 
{
	PiatnashkiTable::PiatnashkiTable()
	{
	}

	bool PiatnashkiTable::isSolved()
	{
		wstring *text = getText();
		int size = getCellsCount().x*getCellsCount().y;

		for (int i = 0; i < size; i++)
			if (text[i] != basicText[i])
				return false;

		return true;
	}


	PiatnashkiTable::~PiatnashkiTable()
	{
	}

	void PiatnashkiTable::updateButtonsModel()
	{
		ButtonsTable::updateButtonsModel();

		if (getCellsCount().x > 0 && getCellsCount().y > 0)
			setEmptyButton(getCellsCount() - Vector2u(1, 1));
	}

	void PiatnashkiTable::setEmptyButton(Vector2u pos)
	{
		updateText();

		emptyButton = getButtonByIndex(pos.y * getCellsCount().x + pos.x);
		emptyButton->setText(L"");
		
		int count = getCellsCount().x*getCellsCount().y;
		for (int i = 0; i < count; i++)
			getButtonByIndex(i)->setEnabled(false);

		if (pos.x > 0)
			getButtonByIndex(pos.y * getCellsCount().x + pos.x - 1)->setEnabled(true);

		if (pos.x < getCellsCount().x-1)
			getButtonByIndex(pos.y * getCellsCount().x + pos.x + 1)->setEnabled(true);

		if (pos.y > 0)
			getButtonByIndex((pos.y-1) * getCellsCount().x + pos.x)->setEnabled(true);

		if (pos.y < getCellsCount().y-1)
			getButtonByIndex((pos.y + 1) * getCellsCount().x + pos.x)->setEnabled(true);
	}

	LabelButton * PiatnashkiTable::getEmptyButton()
	{
		return emptyButton;
	}

	void PiatnashkiTable::setBasicText(wstring * text, int count)
	{
		if (text != basicText)
			delete[] basicText;

		basicText = text;
		setTextCount(count);

		wstring *t = new wstring[count];
		for (int i = 0; i < count; i++)
			t[i] = text[i];

		setText(t, count);
	}

	wstring * PiatnashkiTable::getBasicText()
	{
		return basicText;
	}

	void PiatnashkiTable::swapButtons(Vector2u pos1, Vector2u pos2)
	{
		int index1 = pos1.y*getCellsCount().x + pos1.x;
		int index2 = pos2.y*getCellsCount().x + pos2.x;

		if (index1 >= getTextCount() || index2 >= getTextCount())
			return;

		wstring *texts = getText();

		wstring tmp = texts[index2];
		texts[index2] = texts[index1];
		texts[index1] = tmp;

		if (getButtonByIndex(index1) == emptyButton)
			setEmptyButton(pos2);
		else
		if (getButtonByIndex(index2) == emptyButton)
			setEmptyButton(pos1);
		else
			updateText();
	}

	void PiatnashkiTable::randomize()
	{
		int size = getCellsCount().x*getCellsCount().y;
		if (size > getTextCount())
			return;


		setBasicText(getBasicText(), getTextCount());
		wstring *text = getText();
		for (int i = 0; i < size; i++)
		{
			int index = rand() % size;

			wstring t = text[i];
			text[i] = text[index];
			text[index] = t;
		}

		if (!isCorrect()) 
		{
			randomize();
			return;
		}

		int maxIndex = 0;
		for (int i = 1; i < size; i++)
			if (text[i] == basicText[size - 1])
			{
				maxIndex = i;
				break;
			}

		if (getCellsCount().x > 0 && getCellsCount().y > 0)
			setEmptyButton(Vector2u(maxIndex % getCellsCount().x, maxIndex / getCellsCount().x));
	}

	bool PiatnashkiTable::isCorrect()
	{
		wstring *text = getText();
		int size = getCellsCount().x*getCellsCount().y;

		int parity = 0;

		int maxIndex = 0;
		for (int i = 1; i < size; i++)
			if (text[i] == basicText[size - 1])
			{
				maxIndex = i;
				break;
			}

		for (int i = 0; i < size; i++)
			if(i != maxIndex)
			{
				int val = getIndexInBasic(text[i]);
				for (int j = i + 1; j < size; j++)
					if (val > getIndexInBasic(text[j]))
						parity++;
			}

		if (getCellsCount().x % 2 == 0 && (maxIndex / getCellsCount().x) % 2 == 0)
			parity++;

		return parity % 2 == 0;
	}

	int PiatnashkiTable::getIndexInBasic(wstring text)
	{
		wstring * btext = getBasicText();
		int size = getCellsCount().x*getCellsCount().y;
		for (int i = 0; i < size; i++)
			if (btext[i] == text)
				return i;

		return -1;
	}

	void PiatnashkiTable::rotate()
	{
		wstring *text = getText();
		wstring *t = new wstring[getTextCount()];
		for (int i = 0; i < getTextCount(); i++)
			t[i] = text[i];


		for (int i = 0; i < getCellsCount().y; i++)
			for (int j = 0; j < getCellsCount().x; j++)
				t[i*getCellsCount().x + j] = text[j*getCellsCount().x + getCellsCount().y-i-1];

		setText(t, getTextCount());
	}
}
