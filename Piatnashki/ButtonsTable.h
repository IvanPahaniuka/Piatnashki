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

		void setText(wstring *text, int count);
		wstring* getText();

		int getTextCount();

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

		void render() override;

		void update() override;

		~ButtonsTable();

	protected:
		void draw() override;

		void updateModel() override;
		virtual void updateButtonsModel();

		LabelButton *getActiveButton();
		void setActiveButton(LabelButton *button);

		LabelButton *getButtonByIndex(int index);

		void setTextCount(int count);

		void updateText();
		

	private:
		LabelButton *buttons = nullptr;
		LabelButton *active = nullptr;
		wstring *text = new wstring[0];
		int textCount = 0;
		Font *font = nullptr;
		unsigned int fontSize = 32U;
		Color fillColor = Color::Transparent;
		ClickFunc onClick = nullptr;
		ButtonStateFunc
			onNormalState = nullptr,
			onOverState = nullptr,
			onPressedState = nullptr;
	};
}

