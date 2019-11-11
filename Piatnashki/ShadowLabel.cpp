#include "ShadowLabel.h"

namespace UI 
{
	namespace Styles 
	{
		ShadowLabel::ShadowLabel()
		{
			shadow = new ShadowEffect(*this);
			shadow->setColor(Color::White);
			shadow->setOffset(Vector2f(0, getFontSize() / 10));
		}

		void ShadowLabel::setShadowColor(Color color)
		{
			shadow->setColor(color);
		}

		Color ShadowLabel::getShadowColor()
		{
			return shadow->getColor();
		}

		void ShadowLabel::setShadowOffset(Vector2f offset)
		{
			shadow->setOffset(offset);
		}

		Vector2f ShadowLabel::getShadowOffset()
		{
			return shadow->getOffset();
		}


		ShadowLabel::~ShadowLabel()
		{
		}
	}
}
