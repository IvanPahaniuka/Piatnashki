#pragma once
#include "BorderLabelButton.h"
#include "ShadowEffect.h"

namespace UI 
{
	namespace Styles 
	{
		class ShadowBorderLabelButton: public BorderLabelButton
		{
		public:
			ShadowBorderLabelButton();

			void setGlobalPosition(Vector2f position) override;

			void setNormalOffset(Vector2f offset);
			Vector2f getNormalOffset();

			void setPressedOffsetDl(Vector2f dl);
			Vector2f getPressedOffsetDL();

			void setPressedColor(Color color);
			Color getPressedColor();

			void setFocusedColor(Color color);
			Color getFocusedColor();

			void setNormalColor(Color color);
			Color getNormalColor();

			~ShadowBorderLabelButton();

		private:
			ShadowEffect *shadowNormal,
						 *shadowFocused,
						 *shadowPressed;
			Vector2f* pos = new Vector2f();
		};
	}
}

