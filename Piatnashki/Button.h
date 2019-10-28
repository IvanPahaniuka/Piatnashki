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

		void setNormalState(ButtonStateFunc onNormal);
		void setOverState(ButtonStateFunc onOver);
		void setPressedState(ButtonStateFunc onPressed);
		void setClick(ClickFunc onClick);

		void setEnabled(bool isEnabled);
		bool getEnabled();

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
		ButtonStateFunc
			onNormal, 
			onOver, 
			onPressed;
		ClickFunc
			onClick;
		bool isEnabled = true;
		unsigned int pressedCount = 0;

		void setPressedCount(unsigned int count);
		unsigned int getPressedCount();
	};
}

