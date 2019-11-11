#pragma once
#include "LabelButton.h"
#include "ShadowEffect.h"

namespace UI 
{
	namespace Styles 
	{
		class ShadowLabelButton: public LabelButton
		{
		public:
			ShadowLabelButton();
			
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

			~ShadowLabelButton();

		private:
			ShadowEffect *shadowNormal, 
						 *shadowFocused, 
						 *shadowPressed;
			Vector2f* pos = new Vector2f();
		};
	}
}

