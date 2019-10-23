#pragma once
#include "Table.h"
#include "Label.h"

using namespace std;

namespace UI 
{
	class CharsTable : public Table
	{
	public:
		CharsTable();

		void setWindow(RenderWindow &window) override;

		void setText(wstring text);
		wstring getText();

		void setFont(Font &font);
		Font* getFont();

		void setFontSize(unsigned int fontSize);
		unsigned int getFontSize();

		void setFillColor(Color color) override;
		Color getFillColor() override;

		~CharsTable();
	
	protected:
		void draw() override;

		void updateModel() override;
		virtual void updateLabelsModel();


	private:
		Label *labels = nullptr;
		wstring text = L"";
		Font *font = nullptr;
		unsigned int fontSize = 32U;
		Color fillColor = Color::Transparent;

		void updateText();
	};
}

