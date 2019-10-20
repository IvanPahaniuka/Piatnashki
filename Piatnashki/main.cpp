#pragma once
#include <forward_list>
#include "UI.h"

using namespace sf;
using namespace std;
using namespace UI;

enum class GAME_MODES: int 
{
	EASY = 3,
	NORMAL = 5,
	HARD = 7
};

const Color FOREGROUND_COLOR = Color::Color(255, 255, 255);
const Color BACKGROUND_COLOR = Color::Color(15, 15, 15);

const Color SHADOW_COLOR = Color::Color(125, 125, 125);
const Color FOCUSED_COLOR = Color::Color(238, 17, 55);


forward_list<UIObject*> objects;

void initialize(RenderWindow &window)
{
	GAME_MODES* gameMode = new GAME_MODES(GAME_MODES::NORMAL);

	Font* font = new Font();
	if (!font->loadFromFile("Font.ttf"))
		throw exception("Font loading error!");

#pragma region mainMenu

#pragma region playButton
	{
		BorderLabelButton* button = new BorderLabelButton();
		button->setWindow(window);
		button->setFont(*font);
		button->setFontSize(32U);
		button->setFillColor(FOREGROUND_COLOR);
		button->setText(L"»√–¿“‹");
		button->setSize(Vector2f(220, 50));
		button->setPivot(Vector2f(0.5, 1));
		button->setGlobalPosition(Vector2f(250, 650));
		button->setOutlineThickness(5);
		button->setOutlineColor(FOREGROUND_COLOR);
		objects.push_front(button);

		ShadowEffect* shadow = new ShadowEffect(*button);
		shadow->setColor(SHADOW_COLOR);
		shadow->setOffset(Vector2f(0, 3));

		Vector2f* pos = new Vector2f(button->getGlobalPosition());
		button->setMouseEnterFunc([shadow](UIObject &sender) {
			shadow->setColor(FOCUSED_COLOR);
		});
		button->setMouseExitFunc([shadow, pos](UIObject &sender) {
			shadow->setColor(SHADOW_COLOR);
			shadow->setOffset(Vector2f(0, 3));
			shadow->getTarget()->setGlobalPosition(*pos);
		});
		button->setMouseDownFunc([shadow, pos](UIObject &sender, Mouse::Button button) {
			shadow->setOffset(Vector2f(0, 1));
			*pos = shadow->getTarget()->getGlobalPosition();
			shadow->getTarget()->setGlobalPosition(*pos + Vector2f(0, 2));
		});
		button->setMouseUpFunc([shadow, pos](UIObject &sender, Mouse::Button button) {
			shadow->setOffset(Vector2f(0, 3));
			shadow->getTarget()->setGlobalPosition(*pos);
		});
	}
#pragma endregion

#pragma region modeChosing
	{
		GAME_MODES* lbuttonMode = new GAME_MODES(GAME_MODES::EASY);
		GAME_MODES* rbuttonMode = new GAME_MODES(GAME_MODES::HARD);

		BorderLabelButton *rbutton, *lbutton, *cbutton;

#pragma region centerButton
		cbutton = new BorderLabelButton();
		cbutton->setWindow(window);
		cbutton->setFont(*font);
		cbutton->setFontSize(48U);
		cbutton->setFillColor(FOREGROUND_COLOR);
		cbutton->setText(to_wstring((int)*gameMode) + L"x" + to_wstring((int)*gameMode));
		cbutton->setSize(Vector2f(190, 80));
		cbutton->setPivot(Vector2f(0.5, 0));
		cbutton->setGlobalPosition(Vector2f(250, -5));
		cbutton->setOutlineThickness(5);
		cbutton->setOutlineColor(FOREGROUND_COLOR);
		objects.push_front(cbutton);

		{
			ShadowEffect* shadow = new ShadowEffect(*cbutton);
			shadow->setColor(SHADOW_COLOR);
shadow->setOffset(Vector2f(0, 3));
		}
#pragma endregion
#pragma region leftButton
		lbutton = new BorderLabelButton();
		lbutton->setWindow(window);
		lbutton->setFont(*font);
		lbutton->setFontSize(32U);
		lbutton->setFillColor(FOREGROUND_COLOR);
		lbutton->setText(to_wstring((int)*lbuttonMode) + L"x" + to_wstring((int)*lbuttonMode));
		lbutton->setSize(Vector2f(150, 60));
		lbutton->setPivot(Vector2f(0, 0));
		lbutton->setGlobalPosition(Vector2f(0, -5));
		lbutton->setOutlineThickness(5);
		lbutton->setOutlineColor(FOREGROUND_COLOR);
		objects.push_front(lbutton);

		{
			ShadowEffect* shadow = new ShadowEffect(*lbutton);
			shadow->setColor(SHADOW_COLOR);
			shadow->setOffset(Vector2f(0, 3));

			Vector2f* pos = new Vector2f(lbutton->getGlobalPosition());
			lbutton->setMouseEnterFunc([shadow](UIObject &sender) {
				shadow->setColor(FOCUSED_COLOR);
			});
			lbutton->setMouseExitFunc([shadow, pos](UIObject &sender) {
				shadow->setColor(SHADOW_COLOR);
				shadow->setOffset(Vector2f(0, 3));
				shadow->getTarget()->setGlobalPosition(*pos);
			});
			lbutton->setMouseDownFunc([shadow, pos](UIObject &sender, Mouse::Button button) {
				shadow->setOffset(Vector2f(0, 1));
				*pos = shadow->getTarget()->getGlobalPosition();
				shadow->getTarget()->setGlobalPosition(*pos + Vector2f(0, 2));
			});
			lbutton->setMouseUpFunc([lbutton, cbutton, lbuttonMode, gameMode, shadow, pos](UIObject &sender, Mouse::Button button) {
				shadow->setOffset(Vector2f(0, 3));
				shadow->getTarget()->setGlobalPosition(*pos);

				GAME_MODES tmp = *lbuttonMode;
				*lbuttonMode = *gameMode;
				*gameMode = tmp;

				lbutton->setText(to_wstring((int)*lbuttonMode) + L"x" + to_wstring((int)*lbuttonMode));
				cbutton->setText(to_wstring((int)*gameMode) + L"x" + to_wstring((int)*gameMode));
			});
		}

#pragma endregion
#pragma region rightButton
		rbutton = new BorderLabelButton();
		rbutton->setWindow(window);
		rbutton->setFont(*font);
		rbutton->setFontSize(32U);
		rbutton->setFillColor(FOREGROUND_COLOR);
		rbutton->setText(to_wstring((int)*rbuttonMode) + L"x" + to_wstring((int)*rbuttonMode));
		rbutton->setSize(Vector2f(150, 60));
		rbutton->setPivot(Vector2f(1, 0));
		rbutton->setGlobalPosition(Vector2f(500, -5));
		rbutton->setOutlineThickness(5);
		rbutton->setOutlineColor(FOREGROUND_COLOR);
		objects.push_front(rbutton);

		{
			ShadowEffect* shadow = new ShadowEffect(*rbutton);
			shadow->setColor(SHADOW_COLOR);
			shadow->setOffset(Vector2f(0, 3));

			Vector2f* pos = new Vector2f(rbutton->getGlobalPosition());
			rbutton->setMouseEnterFunc([shadow](UIObject &sender) {
				shadow->setColor(FOCUSED_COLOR);
			});
			rbutton->setMouseExitFunc([shadow, pos](UIObject &sender) {
				shadow->setColor(SHADOW_COLOR);
				shadow->setOffset(Vector2f(0, 3));
				shadow->getTarget()->setGlobalPosition(*pos);
			});
			rbutton->setMouseDownFunc([shadow, pos](UIObject &sender, Mouse::Button button) {
				shadow->setOffset(Vector2f(0, 1));
				*pos = shadow->getTarget()->getGlobalPosition();
				shadow->getTarget()->setGlobalPosition(*pos + Vector2f(0, 2));
			});
			rbutton->setMouseUpFunc([rbutton, cbutton, rbuttonMode, gameMode, shadow, pos](UIObject &sender, Mouse::Button button) {
				shadow->setOffset(Vector2f(0, 3));
				shadow->getTarget()->setGlobalPosition(*pos);

				GAME_MODES tmp = *rbuttonMode;
				*rbuttonMode = *gameMode;
				*gameMode = tmp;

				rbutton->setText(to_wstring((int)*rbuttonMode) + L"x" + to_wstring((int)*rbuttonMode));
				cbutton->setText(to_wstring((int)*gameMode) + L"x" + to_wstring((int)*gameMode));
			});
		}
#pragma endregion
	}
#pragma endregion

#pragma region table
	{
		UI::Rect *rect, *hrect, *vrect;

#pragma region rect
		rect = new UI::Rect();
		rect->setWindow(window);
		rect->setPivot(Vector2f(0.5, 0.5));
		rect->setFillColor(Color::Transparent);
		rect->setOutlineColor(FOREGROUND_COLOR);
		rect->setOutlineThickness(5);
		rect->setSize(Vector2f(304, 304));
		rect->setGlobalPosition(Vector2f(250, 330));

		{
			ShadowEffect *shadow = new ShadowEffect(*rect);
			shadow->setColor(SHADOW_COLOR);
			shadow->setOffset(Vector2f(0, 4));
		}

#pragma endregion

#pragma region vrect
		vrect = new UI::Rect();
		vrect->setWindow(window);
		vrect->setParent(rect);
		vrect->setPivot(Vector2f(0.5, 0.5));
		vrect->setSize(Vector2f(98, 304));
		vrect->setFillColor(Color::Transparent);
		vrect->setOutlineColor(FOREGROUND_COLOR);
		vrect->setOutlineThickness(5);
		vrect->setLocalPosition(Vector2f(0, 0));
		objects.push_front(vrect);
		objects.push_front(rect);

		{
			ShadowEffect *shadow = new ShadowEffect(*vrect);
			shadow->setColor(SHADOW_COLOR);
			shadow->setOffset(Vector2f(0, 4));
		}

#pragma endregion

#pragma region hrect
		hrect = new UI::Rect();
		hrect->setWindow(window);
		hrect->setParent(rect);
		hrect->setPivot(Vector2f(0.5, 0.5));
		hrect->setSize(Vector2f(304, 98));
		hrect->setFillColor(Color::Transparent);
		hrect->setOutlineColor(FOREGROUND_COLOR);
		hrect->setOutlineThickness(5);
		hrect->setLocalPosition(Vector2f(0, 0));
		objects.push_front(hrect);

		{
			ShadowEffect *shadow = new ShadowEffect(*hrect);
			shadow->setColor(SHADOW_COLOR);
			shadow->setOffset(Vector2f(0, 4));
		}

#pragma endregion

#pragma region labels
		wstring txt = L"œﬂ“Õ¿ÿ »";
		
		float dl = 103;
		Vector2f stpoint(-103, -103);
		unsigned int i = 0, j = 0;
		for (i = 0; (i < 3) && (i * 3 + j < txt.length()); i++)
		{
			for (j = 0; (j < 3) && (i * 3 + j < txt.length()); j++)
			{
				Label *label = new Label();
				label->setWindow(window);
				label->setFont(*font);
				label->setFontSize(32U);
				wstring c = L" ";
				c[0] = txt[i * 3 + j];
				label->setText(c);
				label->setParent(rect);
				label->setPivot(Vector2f(0.5, 0.5));
				label->setLocalPosition(stpoint + Vector2f(dl*j, dl*i));
				objects.push_front(label);

				ShadowEffect *shadow = new ShadowEffect(*label);
				shadow->setColor(SHADOW_COLOR);
				shadow->setOffset(Vector2f(0, 3));
			}

			j = 0;
		}

#pragma endregion
		
	}
#pragma endregion

#pragma endregion
}


int main()
{
	RenderWindow window(VideoMode(500, 700), L"œˇÚÌ‡¯ÍË", Style::Close | Style::Titlebar);

	initialize(window);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		
		for (UIObject* obj : objects)
			obj->update();

		window.clear(BACKGROUND_COLOR);
		for (UIObject* obj : objects)
		{
			obj->setPivot(obj->getPivot());
			obj->render();
		}
		window.display();
	}

	return 0;
}