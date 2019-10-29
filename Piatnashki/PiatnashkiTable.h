#pragma once
#include "ButtonsTable.h"

namespace UI 
{
	class PiatnashkiTable : public ButtonsTable
	{
	public:
		PiatnashkiTable();

		virtual void setEmptyButton(Vector2u pos);
		LabelButton *getEmptyButton();
		
		void setBasicText(wstring *text, int count);
		wstring *getBasicText();

		void swapButtons(Vector2u pos1, Vector2u pos2);

		void randomize();

		~PiatnashkiTable();

	protected:
		void updateButtonsModel() override;

		bool isCorrect();
		int getIndexInBasic(wstring text);
		void rotate();

	private:
		LabelButton *emptyButton = nullptr;
		wstring *basicText = nullptr;
	};
}

