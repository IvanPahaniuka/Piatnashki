#pragma once
#include "Label.h"
#include "ShadowEffect.h"

namespace UI
{
	namespace Styles
	{
		class ShadowLabel : public Label
		{
		public:
			ShadowLabel();
			
			void setShadowColor(Color color);
			Color getShadowColor();

			void setShadowOffset(Vector2f offset);
			Vector2f getShadowOffset();

			~ShadowLabel();

		private:
			ShadowEffect *shadow;

		};
	}
}

