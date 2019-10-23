#pragma once
#include "LabelButton.h"
#include "Rect.h"

using namespace std;

namespace UI 
{
	class BorderLabelButton: public LabelButton
	{
	public:
		BorderLabelButton();

		void setWindow(RenderWindow &window) override;

		void setOutlineColor(Color outlineColor) override;
		Color getOutlineColor() override;

		void setOutlineThickness(float thickness) override;
		float getOutlineThickness() override;

		~BorderLabelButton();

	protected:
		void updateRect() override;
		void draw() override;

	private:
		Rect border;
	};
}

