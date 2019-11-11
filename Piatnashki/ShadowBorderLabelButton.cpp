#include "ShadowBorderLabelButton.h"


namespace UI
{
	namespace Styles
	{
		ShadowBorderLabelButton::ShadowBorderLabelButton()
		{
			shadowNormal = new ShadowEffect(*this);
			setNormalColor(Color::White);

			shadowFocused = new ShadowEffect();
			setFocusedColor(Color::Red);

			shadowPressed = new ShadowEffect();
			setPressedColor(Color::Blue);
			setNormalOffset(Vector2f(0, getFontSize() / 10));
			setPressedOffsetDl(Vector2f(0, -(int)getFontSize() / 20));

			*pos = this->getGlobalPosition();
			this->setOverState([&](UIObject &sender) {
				shadowNormal->setTarget(nullptr);
				shadowFocused->setTarget(this);
				shadowPressed->setTarget(nullptr);

				this->setGlobalPosition(*pos);
			});
			this->setNormalState([&](UIObject &sender) {
				shadowNormal->setTarget(this);
				shadowFocused->setTarget(nullptr);
				shadowPressed->setTarget(nullptr);

				this->setGlobalPosition(*pos);
			});
			this->setPressedState([&](UIObject &sender) {
				shadowNormal->setTarget(nullptr);
				shadowFocused->setTarget(nullptr);
				shadowPressed->setTarget(this);

				this->setGlobalPosition(*pos - getPressedOffsetDL());
			});
		}

		void ShadowBorderLabelButton::setGlobalPosition(Vector2f position)
		{
			BorderLabelButton::setGlobalPosition(position);

			if (shadowPressed->getTarget() != this)
				*pos = position;
			else
				*pos = position + getPressedOffsetDL();
		}

		void ShadowBorderLabelButton::setNormalOffset(Vector2f offset)
		{
			Vector2f dl = getPressedOffsetDL();
			shadowNormal->setOffset(offset);
			shadowFocused->setOffset(offset);
			setPressedOffsetDl(dl);

		}

		Vector2f ShadowBorderLabelButton::getNormalOffset()
		{
			return shadowNormal->getOffset();
		}

		void ShadowBorderLabelButton::setPressedOffsetDl(Vector2f dl)
		{
			shadowPressed->setOffset(getNormalOffset() + dl);
		}

		Vector2f ShadowBorderLabelButton::getPressedOffsetDL()
		{
			return shadowPressed->getOffset() - getNormalOffset();
		}


		void ShadowBorderLabelButton::setPressedColor(Color color)
		{
			shadowPressed->setColor(color);
		}

		Color ShadowBorderLabelButton::getPressedColor()
		{
			return shadowPressed->getColor();
		}

		void ShadowBorderLabelButton::setFocusedColor(Color color)
		{
			shadowFocused->setColor(color);
		}

		Color ShadowBorderLabelButton::getFocusedColor()
		{
			return shadowFocused->getColor();
		}

		void ShadowBorderLabelButton::setNormalColor(Color color)
		{
			shadowNormal->setColor(color);
		}

		Color ShadowBorderLabelButton::getNormalColor()
		{
			return shadowNormal->getColor();
		}

		ShadowBorderLabelButton::~ShadowBorderLabelButton()
		{
		}
	}
}
