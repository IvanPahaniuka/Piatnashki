#include "UIObject.h"
#include "Effect.h"


using namespace sf;
using namespace std;

namespace UI
{
	UIObject::UIObject()
	{
	}
	
	void UIObject::render()
	{
		if (getActive())
		{
			for each (Effect* effect in effects)
				effect->draw();

			draw();
		}
	}

	RenderWindow * UIObject::getWindow()
	{
		return window;
	}

	void UIObject::setWindow(RenderWindow & window)
	{
		this->window = &window;
	}

	void UIObject::setPivot(Vector2f pivot)
	{
		this->pivot = pivot;
		updatePivot();
	}

	Vector2f UIObject::getPivot()
	{
		return pivot;
	}

	Color UIObject::getFillColor()
	{
		return Color::Transparent;
	}

	Color UIObject::getOutlineColor()
	{
		return Color::Transparent;
	}

	float UIObject::getOutlineThickness()
	{
		return 0.0f;
	}

	void UIObject::effectAdd(Effect & effect)
	{
		effects.push_front(&effect);
	}

	void UIObject::effectRemove(Effect & effect)
	{
		effects.remove(&effect);
	}

}
