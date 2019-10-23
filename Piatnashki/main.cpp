#pragma once
#include <forward_list>
#include "UI.h"

using namespace sf;
using namespace std;
using namespace UI;

enum class GAME_MODES: int 
{
	EASY = 3,
	NORMAL = 4,
	HARD = 5
};

const Color FOREGROUND_COLOR = Color::Color(255, 255, 255);
const Color BACKGROUND_COLOR = Color::Color(15, 15, 15);

const Color SHADOW_COLOR = Color::Color(125, 125, 125);
const Color FOCUSED_COLOR = Color::Color(238, 17, 55);

const Vector2f GAMEFIELD_SIZE = Vector2f(389, 389);
const float GAMEFIELD_THICKNESS = 7;


forward_list<UIObject*> objects;

void initialize(RenderWindow &window)
{
	GAME_MODES* gameMode = new GAME_MODES(GAME_MODES::NORMAL);

	Font* font = new Font();
	if (!font->loadFromFile("Font.ttf"))
		throw exception("Font loading error!");

	Object *mainMenu = new Object();
	Object *gameMenu = new Object();

#pragma region GameMenu
#pragma region Timer
	{
		LabelButton *timerButton = new LabelButton();
		timerButton->setWindow(window);
		timerButton->setFont(*font);
		timerButton->setParent(gameMenu);
		timerButton->setFontSize(48U);
		timerButton->setText(L"00:00");
		timerButton->setPivot(Vector2f(0.5, 0.5));
		timerButton->setGlobalPosition(Vector2f(250, 65));
		timerButton->setFillColor(FOREGROUND_COLOR);
		timerButton->setSize(Vector2f(250, 50));
		objects.push_front(timerButton);

		ShadowEffect* shadow = new ShadowEffect(*timerButton);
		shadow->setColor(SHADOW_COLOR);
		shadow->setOffset(Vector2f(0, 3));

		Vector2f* pos = new Vector2f(timerButton->getGlobalPosition());
		timerButton->setMouseEnterFunc([shadow](UIObject &sender) {
			shadow->setColor(FOCUSED_COLOR);
		});
		timerButton->setMouseExitFunc([shadow, pos](UIObject &sender) {
			shadow->setColor(SHADOW_COLOR);
			shadow->setOffset(Vector2f(0, 3));
			shadow->getTarget()->setGlobalPosition(*pos);
		});
		timerButton->setMouseDownFunc([shadow, pos](UIObject &sender, Mouse::Button button) {
			shadow->setOffset(Vector2f(0, 1));
			*pos = shadow->getTarget()->getGlobalPosition();
			shadow->getTarget()->setGlobalPosition(*pos + Vector2f(0, 2));
		});
		timerButton->setMouseUpFunc([shadow, pos](UIObject &sender, Mouse::Button button) {
			shadow->setOffset(Vector2f(0, 3));
			shadow->getTarget()->setGlobalPosition(*pos);
		});

	}
#pragma endregion

#pragma region GameField
	Table *gameTable;
	{
		gameTable = new Table();
		gameTable->setWindow(window);
		gameTable->setPivot(Vector2f(0.5, 0.5));
		gameTable->setOutlineColor(FOREGROUND_COLOR);
		gameTable->setOutlineThickness(GAMEFIELD_THICKNESS);
		gameTable->setSize(GAMEFIELD_SIZE);
		gameTable->setGlobalPosition(Vector2f(250, 340));
		gameTable->setParent(gameMenu);
		objects.push_front(gameTable);

		{
			ShadowEffect *shadow = new ShadowEffect(*gameTable);
			shadow->setColor(SHADOW_COLOR);
			shadow->setOffset(Vector2f(0, 4));
		}
	}
#pragma endregion

#pragma region MainMenuButton

	{
		BorderLabelButton* button = new BorderLabelButton();
		button->setWindow(window);
		button->setFont(*font);
		button->setFontSize(32U);
		button->setFillColor(FOREGROUND_COLOR);
		button->setText(L"ÌÅÍÞ");
		button->setSize(Vector2f(210, 60));
		button->setPivot(Vector2f(1, 1));
		button->setGlobalPosition(Vector2f(247, 655));
		button->setOutlineThickness(6);
		button->setOutlineColor(FOREGROUND_COLOR);
		button->setParent(gameMenu);
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
		button->setMouseUpFunc([shadow, pos, gameMenu, mainMenu, gameTable, gameMode](UIObject &sender, Mouse::Button button) {
			shadow->setOffset(Vector2f(0, 3));
			shadow->getTarget()->setGlobalPosition(*pos);

			mainMenu->setActive(true);
			gameMenu->setActive(false);
		});
	}


#pragma endregion

#pragma region RestartButton

	{
		BorderLabelButton* button = new BorderLabelButton();
		button->setWindow(window);
		button->setFont(*font);
		button->setFontSize(32U);
		button->setFillColor(FOREGROUND_COLOR);
		button->setText(L"ÇÀÍÎÂÎ");
		button->setSize(Vector2f(210, 60));
		button->setPivot(Vector2f(0, 1));
		button->setGlobalPosition(Vector2f(253, 655));
		button->setOutlineThickness(6);
		button->setOutlineColor(FOREGROUND_COLOR);
		button->setParent(gameMenu);
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
		button->setMouseUpFunc([shadow, pos, gameMenu, mainMenu, gameTable, gameMode](UIObject &sender, Mouse::Button button) {
			shadow->setOffset(Vector2f(0, 3));
			shadow->getTarget()->setGlobalPosition(*pos);

			mainMenu->setActive(true);
			gameMenu->setActive(false);
		});
	}


#pragma endregion

#pragma endregion

#pragma region MainMenu
#pragma region playButton
	{
		BorderLabelButton* button = new BorderLabelButton();
		button->setWindow(window);
		button->setFont(*font);
		button->setFontSize(32U);
		button->setFillColor(FOREGROUND_COLOR);
		button->setText(L"ÈÃÐÀÒÜ");
		button->setSize(Vector2f(220, 50));
		button->setPivot(Vector2f(0.5, 1));
		button->setGlobalPosition(Vector2f(250, 650));
		button->setOutlineThickness(5);
		button->setOutlineColor(FOREGROUND_COLOR);
		button->setParent(mainMenu);
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
		button->setMouseUpFunc([shadow, pos, gameMenu, mainMenu, gameTable, gameMode](UIObject &sender, Mouse::Button button) {
			shadow->setOffset(Vector2f(0, 3));
			shadow->getTarget()->setGlobalPosition(*pos);

			gameTable->setCellsCount(Vector2u((unsigned int)*gameMode, (unsigned int)*gameMode));

			mainMenu->setActive(false);
			gameMenu->setActive(true);
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
		cbutton->setParent(mainMenu);
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
		lbutton->setParent(mainMenu);
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
		rbutton->setParent(mainMenu);
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

#pragma region Table
	{
		CharsTable *table = new CharsTable();
		table->setWindow(window);
		table->setPivot(Vector2f(0.5, 0.5));
		table->setFillColor(FOREGROUND_COLOR);
		table->setOutlineColor(FOREGROUND_COLOR);
		table->setOutlineThickness(5);
		table->setSize(Vector2f(304, 304));
		table->setGlobalPosition(Vector2f(250, 330));
		table->setCellsCount(Vector2u(3, 3));
		table->setParent(mainMenu);
		table->setText(L"ÏßÒÍÀØÊÈ");
		table->setFont(*font);
		table->setFontSize(32U);
		
		objects.push_front(table);

		{
			ShadowEffect *shadow = new ShadowEffect(*table);
			shadow->setColor(SHADOW_COLOR);
			shadow->setOffset(Vector2f(0, 4));
		}

	}
#pragma endregion
#pragma endregion

	gameMenu->setActive(false);
}


int main()
{
	RenderWindow window(VideoMode(500, 700), L"Ïÿòíàøêè", Style::Close | Style::Titlebar);

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