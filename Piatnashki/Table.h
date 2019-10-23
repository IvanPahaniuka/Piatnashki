#pragma once
#include "Rect.h"

namespace UI 
{
	class Table: public UI::Rect
	{
	public:
		Table();

		void setWindow(RenderWindow &window) override;

		virtual void setSize(Vector2f size);

		virtual void setCellsCount(Vector2u cellsCount);
		Vector2u getCellsCount();

		void setOutlineColor(Color outlineColor) override;

		void setOutlineThickness(float thickness) override;
		~Table();

	protected:
		void draw() override;

		virtual void updateModel();
		virtual void updateHModel();
		virtual void updateVModel();

	private:
		Vector2u cellsCount = Vector2u();

		UI::Rect *vrects = nullptr, 
				 *hrects = nullptr;

		unsigned int getVRectCount();
		unsigned int getHRectCount();

	};
}

