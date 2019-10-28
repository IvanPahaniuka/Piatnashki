#pragma once
#include "Table.h"
#include "LabelButton.h"

namespace UI 
{
	class ButtonsTable : public Table
	{
	public:
		typedef function<void(UIObject &sender, Mouse::Button button, Vector2u cell)> TableClickFunc;

		ButtonsTable();

		void setWindow(RenderWindow &window) override;

		void setText(wstring text);
		wstring getText();

		void setFont(Font &font);
		Font* getFont();

		void setFontSize(unsigned int fontSize);
		unsigned int getFontSize();

		void setFillColor(Color color);
		Color getFillColor();

		Vector2i getCellByObject(UIObject *obj);

		virtual void setNormalState(ButtonStateFunc onNormal);
		virtual void setOverState(ButtonStateFunc onOver);
		virtual void setPressedState(ButtonStateFunc onPressed);
		virtual void setClick(ClickFunc onClick);

		void update() override;

		~ButtonsTable();

	protected:
		void draw() override;

		void updateModel() override;
		virtual void updateButtonsModel();

	private:
		LabelButton *buttons = nullptr;
		wstring text = L"";
		Font *font = nullptr;
		unsigned int fontSize = 32U;
		Color fillColor = Color::Transparent;
		ClickFunc onClick = nullptr;
		ButtonStateFunc
			onNormalState = nullptr,
			onOverState = nullptr,
			onPressedState = nullptr;

		void updateText();
	};
}

