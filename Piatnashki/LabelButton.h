#pragma once
#include "Button.h"
#include "Label.h"

using namespace std;

namespace UI 
{
	class LabelButton : public Button
	{
	public:
		LabelButton();

		void setWindow(RenderWindow &window) override;

		void setText(wstring text);
		wstring getText();

		void setFont(Font &font);
		const Font* getFont();

		void setFontSize(unsigned int fontSize);
		unsigned int getFontSize();

		void setFillColor(Color fillColor) override;
		Color getFillColor() override;

		void setOutlineColor(Color outlineColor) override;
		Color getOutlineColor() override;

		void setOutlineThickness(float thickness) override;
		float getOutlineThickness() override;

		~LabelButton();

	protected:
		void updateRect() override;
		void draw() override;

	private:
		Label label;
	};
}

