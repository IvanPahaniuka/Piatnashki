#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "UIObject.h"

using namespace std;
using namespace sf;

namespace UI 
{
	class Rect: public UIObject
	{
	public:
		Rect();

		void setSize(Vector2f size);
		Vector2f getSize();

		void setGlobalPosition(Vector2f position) override;

		void setFillColor(Color fillColor) override;
		Color getFillColor() override;

		void setOutlineColor(Color outlineColor) override;
		Color getOutlineColor() override;

		void setOutlineThickness(float thickness) override;
		float getOutlineThickness() override;

		~Rect();

	protected:
		void updatePivot() override;
		void draw() override;

	private:
		RectangleShape rect;

	};
}

