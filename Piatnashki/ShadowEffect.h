#pragma once
#include "Effect.h"

using namespace std;

namespace UI
{
	class ShadowEffect : public Effect
	{
	public:
		ShadowEffect();

		ShadowEffect(UIObject &target);

		void draw() override;

		void setColor(Color color);
		Color getColor();

		void setOffset(Vector2f offset);
		Vector2f getOffset();

		~ShadowEffect();

	private:
		Color color;
		Vector2f offset;
	};
}


