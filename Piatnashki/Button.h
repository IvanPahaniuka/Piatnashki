#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "UIObject.h"

using namespace std;
using namespace sf;

namespace UI
{
	class Button: public UIObject
	{
	public:
		Button();
		
		void setGlobalPosition(Vector2f position) override;

		Vector2f getSize();
		virtual void setSize(Vector2f size);

		bool isMouseUnder();
		bool isMousePressed(Mouse::Button button);

		void setMouseEnterFunc(MouseMovingFunc func);
		void setMouseExitFunc(MouseMovingFunc func);
		void setMouseDownFunc(MousePressingFunc func); 
		void setMouseUpFunc(MousePressingFunc func);

		FloatRect getBounds();

		void update() override;

		~Button();

	protected:
		virtual void updateRect();
		void updatePivot() override;

	private:
		Vector2f size = Vector2f(0, 0);
		bool isUnder = false;
		FloatRect rect;
		bool isPressed[Mouse::ButtonCount];
		MouseMovingFunc
			onMouseEnter, 
			onMouseExit;
		MousePressingFunc
			onMouseDown, 
			onMouseUp;
	};
}

