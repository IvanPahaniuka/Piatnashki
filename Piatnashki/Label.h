#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "UIObject.h"

using namespace std;
using namespace sf;

namespace UI
{
	class Label: public UIObject
	{
	public:
		Label();

		void setText(wstring text);
		wstring getText();

		void setFont(Font &font);
		const Font* getFont();

		void setFontSize(unsigned int fontSize);
		unsigned int getFontSize();

		void setGlobalPosition(Vector2f position) override;

		void setFillColor(Color fillColor) override;
		Color getFillColor() override;

		void setOutlineColor(Color outlineColor) override;
		Color getOutlineColor() override;

		void setOutlineThickness(float thickness) override;
		float getOutlineThickness() override;

		~Label();

	protected:
		Text text;

		void updatePivot() override;

		void draw() override;


	};
}

