#include "ShadowLabelButton.h"


namespace UI 
{
	namespace Styles 
	{
		ShadowLabelButton::ShadowLabelButton()
		{
			shadowNormal = new ShadowEffect(*this);
			setNormalColor(Color::White);

			shadowFocused = new ShadowEffect();
			setFocusedColor(Color::Red);

			shadowPressed = new ShadowEffect();
			setPressedColor(Color::Blue);
			setNormalOffset(Vector2f(0, getFontSize() / 10));
			setPressedOffsetDl(Vector2f(0,  -(int)getFontSize() / 20));

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

		void ShadowLabelButton::setGlobalPosition(Vector2f position)
		{
			LabelButton::setGlobalPosition(position);

			if (shadowPressed->getTarget() != this)
				*pos = position;
			else
				*pos = position + getPressedOffsetDL();
		}

		void ShadowLabelButton::setNormalOffset(Vector2f offset)
		{
			Vector2f dl = getPressedOffsetDL();
			shadowNormal->setOffset(offset);
			shadowFocused->setOffset(offset);
			setPressedOffsetDl(dl);
			
		}

		Vector2f ShadowLabelButton::getNormalOffset()
		{
			return shadowNormal->getOffset();
		}

		void ShadowLabelButton::setPressedOffsetDl(Vector2f dl)
		{
			shadowPressed->setOffset(getNormalOffset() + dl);
		}

		Vector2f ShadowLabelButton::getPressedOffsetDL()
		{
			return shadowPressed->getOffset() - getNormalOffset();
		}


		void ShadowLabelButton::setPressedColor(Color color)
		{
			shadowPressed->setColor(color);
		}

		Color ShadowLabelButton::getPressedColor()
		{
			return shadowPressed->getColor();
		}

		void ShadowLabelButton::setFocusedColor(Color color)
		{
			shadowFocused->setColor(color);
		}

		Color ShadowLabelButton::getFocusedColor()
		{
			return shadowFocused->getColor();
		}

		void ShadowLabelButton::setNormalColor(Color color)
		{
			shadowNormal->setColor(color);
		}

		Color ShadowLabelButton::getNormalColor()
		{
			return shadowNormal->getColor();
		}

		ShadowLabelButton::~ShadowLabelButton()
		{
		}
	}
}
