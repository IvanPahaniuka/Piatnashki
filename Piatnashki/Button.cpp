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

	void Button::setNormalState(ButtonStateFunc onNormal)
	{
		this->onNormal = onNormal;
	}

	void Button::setOverState(ButtonStateFunc onOver)
	{
		this->onOver = onOver;
	}

	void Button::setPressedState(ButtonStateFunc onPressed)
	{
		this->onPressed = onPressed;
	}

	void Button::setClick(ClickFunc onClick)
	{
		this->onClick = onClick;
	}

	void Button::setEnabled(bool isEnabled)
	{
		this->isEnabled = isEnabled;

		if (!isEnabled)
		{
			fill(isPressed, isPressed + Mouse::Button::ButtonCount, false);
			setPressedCount(0);
			isUnder = false;

			if (onNormal != nullptr)
				onNormal(*this);
		}
	}

	bool Button::getEnabled()
	{
		return isEnabled;
	}

	FloatRect Button::getBounds()
	{
		return rect;
	}

	void Button::update()
	{
		UIObject::update();

		if (getActive() && getEnabled())
		{
			if (getBounds().contains(Vector2f(Mouse::getPosition(*getWindow()))) != isUnder)
			{
				if (isUnder)
				{
					fill(isPressed, isPressed + Mouse::Button::ButtonCount, false);
					setPressedCount(0);

					if (onNormal != nullptr)
						onNormal(*this);
				}
				else
				{
					if (onOver != nullptr)
						onOver(*this);
				}

				isUnder = !isUnder;
			}

			if (isUnder)
				for (int i = 0; i < Mouse::Button::ButtonCount; i++)
					if (!isPressed[i] && Mouse::isButtonPressed((Mouse::Button)i))
					{
						isPressed[i] = true;
						setPressedCount(getPressedCount() + 1);
					}
					else
						if (isPressed[i] && !Mouse::isButtonPressed((Mouse::Button)i))
						{
							isPressed[i] = false;
							setPressedCount(getPressedCount() - 1);

							if (onClick != nullptr)
								onClick(*this, (Mouse::Button)i);
						}
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

	void Button::setPressedCount(unsigned int count)
	{
		if (count > Mouse::ButtonCount)
			return;

		if (pressedCount == 0 && count > 0)
			if (onPressed != nullptr)
				onPressed(*this);

		if (count == 0 && pressedCount > 0)
			if (onOver != nullptr)
				onOver(*this);


		pressedCount = count;

	}

	unsigned int Button::getPressedCount()
	{
		return pressedCount;
	}

	Button::~Button()
	{
	}
}
