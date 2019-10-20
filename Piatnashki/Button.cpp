#include "Button.h"

using namespace std;
using namespace sf;

namespace UI
{
	Button::Button() {
		fill(isPressed, isPressed + Mouse::Button::ButtonCount, false);
	}

	Vector2f Button::getSize() {
		return size;
	}
	void Button::setSize(Vector2f size)
	{
		this->size = size;
		updateRect();
		updatePivot();
	}

	bool Button::isMouseUnder()
	{
		return isUnder;
	}
	
	bool Button::isMousePressed(Mouse::Button button)
	{
		return isPressed[button];
	}

	void Button::setMouseEnterFunc(MouseMovingFunc func)
	{
		onMouseEnter = func;
	}

	void Button::setMouseExitFunc(MouseMovingFunc func)
	{
		onMouseExit = func;
	}

	void Button::setMouseDownFunc(MousePressingFunc func)
	{
		onMouseDown = func;
	}

	void Button::setMouseUpFunc(MousePressingFunc func)
	{
		onMouseUp = func;
	}

	FloatRect Button::getBounds()
	{
		return rect;
	}

	void Button::update()
	{
		UIObject::update();

		if (getBounds().contains(Vector2f(Mouse::getPosition(*getWindow()))) != isUnder)
		{
			if (isUnder)
			{
				if (onMouseExit != nullptr)
					onMouseExit(*this);

				fill(isPressed, isPressed + Mouse::Button::ButtonCount, false);
			}
			else
			{
				if (onMouseEnter != nullptr)
					onMouseEnter(*this);
			}

			isUnder = !isUnder;
		}

		if (isUnder)
			for (int i = 0; i < Mouse::Button::ButtonCount; i++)
				if (!isPressed[i] && Mouse::isButtonPressed((Mouse::Button)i))
				{
					isPressed[i] = true;

					if (onMouseDown != nullptr)
						onMouseDown(*this, (Mouse::Button)i);
				}
				else
				if (isPressed[i] && !Mouse::isButtonPressed((Mouse::Button)i))
				{
					isPressed[i] = false;

					if (onMouseUp != nullptr)
						onMouseUp(*this, (Mouse::Button)i);
				}
	}

	void Button::setGlobalPosition(Vector2f position)
	{
		UIObject::setGlobalPosition(position);

		updateRect();
	}

	void Button::updateRect()
	{
		rect = FloatRect(getGlobalPosition() -
			Vector2f(getPivot().x * getSize().x, getPivot().y * getSize().y),
			getSize());
	}

	void Button::updatePivot()
	{
		UIObject::updatePivot();

		updateRect();
	}

	Button::~Button()
	{
	}
}
