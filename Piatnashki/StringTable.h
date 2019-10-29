#pragma once
#include "Table.h"
#include "Label.h"

using namespace std;

namespace UI 
{
	class StringTable : public Table
	{
	public:
		StringTable();

		void setWindow(RenderWindow &window) override;

		void setText(wstring *text, int count);
		wstring* getText();

		void setFont(Font &font);
		Font* getFont();

		void setFontSize(unsigned int fontSize);
		unsigned int getFontSize();

		void setFillColor(Color color) override;
		Color getFillColor() override;

		~StringTable();
	
	protected:
		void draw() override;

		void updateModel() override;
		virtual void updateLabelsModel();


	private:
		Label *labels = nullptr;
		wstring *text = new wstring[0];
		int textCount = 0;
		Font *font = nullptr;
		unsigned int fontSize = 32U;
		Color fillColor = Color::Transparent;

		void updateText();
	};
}

