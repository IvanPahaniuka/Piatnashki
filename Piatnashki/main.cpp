#pragma once
#include <forward_list>
#include "UI.h"
#include "Styles.h"

using namespace sf;
using namespace std;
using namespace UI;
using namespace UI::Styles;

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
	if (!font->loadFromFile("Font.otf"))
		throw exception("Font loading error!");

	Object *mainMenu = new Object();
	Object *gameMenu = new Object();
	Object *solvedMenu = new Object();

	ShadowLabel *solvedSteps = new ShadowLabel();


#pragma region GameMenu
#pragma region Steps
	ShadowLabel *steps = new ShadowLabel();
	int *stepsInt = new int(0);
	{
		steps->setWindow(window);
		steps->setFont(*font);
		steps->setParent(gameMenu);
		steps->setFontSize(48U);
		steps->setText(L"0");
		steps->setPivot(Vector2f(0.5, 0.5));
		steps->setGlobalPosition(Vector2f(250, 65));
		steps->setFillColor(FOREGROUND_COLOR);
		steps->setShadowColor(SHADOW_COLOR);
		steps->setShadowOffset(Vector2f(0, 5));
		objects.push_front(steps);
	}
#pragma endregion

#pragma region GameField
	PiatnashkiTable *gameTable;
	{
		gameTable = new PiatnashkiTable();
		gameTable->setWindow(window);
		gameTable->setPivot(Vector2f(0.5, 0.5));
		gameTable->setOutlineColor(FOREGROUND_COLOR);
		gameTable->setOutlineThickness(GAMEFIELD_THICKNESS);
		gameTable->setSize(GAMEFIELD_SIZE);
		gameTable->setGlobalPosition(Vector2f(250, 340));
		gameTable->setParent(gameMenu);
		gameTable->setBasicText(new wstring[25]{L"1", L"2", L"3", L"4", L"5", L"6", 
			L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", 
			L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25" }, 25);
		gameTable->setFont(*font);
		gameTable->setFillColor(FOREGROUND_COLOR);
		gameTable->setFontSize(32U);
		objects.push_front(gameTable);

		{
			ShadowEffect *shadow = new ShadowEffect(*gameTable);
			shadow->setColor(SHADOW_COLOR);
			shadow->setOffset(Vector2f(0, 3));
		}

		{
			ShadowEffect *shadow = new ShadowEffect();
			shadow->setColor(SHADOW_COLOR);
			shadow->setOffset(Vector2f(0, 3));

			Vector2f *pos = new Vector2f();
			gameTable->setNormalState([shadow, pos](UIObject &sender) 
			{
				if (shadow->getTarget() != &sender)
				{
					if (shadow->getTarget() != nullptr)
						shadow->getTarget()->setGlobalPosition(*pos);
					*pos = sender.getGlobalPosition();
				}

				shadow->setTarget(nullptr);

				sender.setGlobalPosition(*pos);
			});

			gameTable->setOverState([shadow, pos](UIObject &sender) {
				if (shadow->getTarget() != &sender)
				{
					if (shadow->getTarget() != nullptr)
						shadow->getTarget()->setGlobalPosition(*pos);
					*pos = sender.getGlobalPosition();
				}

				shadow->setTarget(&sender);
				shadow->setColor(FOCUSED_COLOR);
				shadow->setOffset(Vector2f(0, 3));

				sender.setGlobalPosition(*pos);
			});

			gameTable->setPressedState([shadow, pos](UIObject &sender) {

				if (shadow->getTarget() != &sender)
				{
					if (shadow->getTarget() != nullptr)
						shadow->getTarget()->setGlobalPosition(*pos);
					*pos = sender.getGlobalPosition();
				}

				shadow->setTarget(&sender);
				shadow->setColor(FOCUSED_COLOR);
				shadow->setOffset(Vector2f(0, 1));

				sender.setGlobalPosition(*pos + Vector2f(0, 2));

			});

			gameTable->setClick([gameMenu, solvedMenu, solvedSteps, gameTable, stepsInt, steps](UIObject &sender, Mouse::Button button) {
				Vector2i clicked = gameTable->getCellByObject(&sender);
				Vector2i empty = gameTable->getCellByObject(gameTable->getEmptyButton());

				if (*stepsInt < INT_MAX)
					*stepsInt += 1;
				steps->setText(to_wstring(*stepsInt));

				Vector2u pos1 = Vector2u(clicked.x, clicked.y);
				Vector2u pos2 = Vector2u(empty.x, empty.y);
				gameTable->swapButtons(pos1, pos2);

				if (gameTable->isSolved()) {
					solvedSteps->setText(steps->getText());

					gameMenu->setActive(false);
					solvedMenu->setActive(true);
				}
			});
		}
	}
#pragma endregion

#pragma region MainMenuButton

	{
		ShadowBorderLabelButton* button = new ShadowBorderLabelButton();
		button->setWindow(window);
		button->setFont(*font);
		button->setFontSize(32U);
		button->setFillColor(FOREGROUND_COLOR);
		button->setText(L"ÌÅÍÞ");
		button->setSize(Vector2f(220, 50));
		button->setPivot(Vector2f(0.5, 1));
		button->setGlobalPosition(Vector2f(250, 650));
		button->setOutlineThickness(5);
		button->setOutlineColor(FOREGROUND_COLOR);
		button->setParent(gameMenu);
		button->setNormalColor(SHADOW_COLOR);
		button->setFocusedColor(FOCUSED_COLOR);
		button->setPressedColor(FOCUSED_COLOR);
		button->setNormalOffset(Vector2f(0, 3));
		button->setPressedOffsetDl(Vector2f(0, -2));
		objects.push_front(button);

		button->setClick([gameMenu, mainMenu](UIObject &sender, Mouse::Button button) {
			mainMenu->setActive(true);
			gameMenu->setActive(false);
		});
	}


#pragma endregion

#pragma endregion

#pragma region SolvedMenu
#pragma region WinText
	{
		ShadowLabel *label = new ShadowLabel();
		label->setWindow(window);
		label->setFont(*font);
		label->setParent(solvedMenu);
		label->setText(L"ÏÎÁÅÄÀ");
		label->setFillColor(FOREGROUND_COLOR);
		label->setPivot(Vector2f(0.5, 0.5));
		label->setGlobalPosition(Vector2f(250, 250));
		label->setFontSize(56U);
		label->setShadowColor(SHADOW_COLOR);
		label->setShadowOffset(Vector2f(0, 6));
		objects.push_front(label);
	}
#pragma endregion

#pragma region MainMenu
	{
		ShadowLabelButton *button = new ShadowLabelButton();
		button->setWindow(window);
		button->setFont(*font);
		button->setParent(solvedMenu);
		button->setText(L"ãëàâíîå ìåíþ");
		button->setFontSize(24U);
		button->setFillColor(FOREGROUND_COLOR);
		button->setPivot(Vector2f(0.5, 0.5));
		button->setGlobalPosition(Vector2f(250, 340));
		button->setSize(Vector2f(300, 40));
		button->setNormalColor(SHADOW_COLOR);
		button->setFocusedColor(FOCUSED_COLOR);
		button->setPressedColor(FOCUSED_COLOR);
		button->setNormalOffset(Vector2f(0, 3));
		button->setPressedOffsetDl(Vector2f(0, -2));
		objects.push_front(button);

		button->setClick([solvedMenu, mainMenu](UIObject &sender, Mouse::Button button) {
			solvedMenu->setActive(false);
			mainMenu->setActive(true);
		});
	}
#pragma endregion

#pragma region NewGame
	{
		ShadowLabelButton *button = new ShadowLabelButton();
		button->setWindow(window);
		button->setFont(*font);
		button->setParent(solvedMenu);
		button->setText(L"íîâàÿ èãðà");
		button->setFontSize(24U);
		button->setFillColor(FOREGROUND_COLOR);
		button->setPivot(Vector2f(0.5, 0.5));
		button->setGlobalPosition(Vector2f(250, 384));
		button->setSize(Vector2f(250, 40));
		button->setNormalColor(SHADOW_COLOR);
		button->setFocusedColor(FOCUSED_COLOR);
		button->setPressedColor(FOCUSED_COLOR);
		button->setNormalOffset(Vector2f(0, 3));
		button->setPressedOffsetDl(Vector2f(0, -2));
		objects.push_front(button);

		button->setClick([gameMenu, solvedMenu, gameTable, gameMode, stepsInt, steps](UIObject &sender, Mouse::Button button) {
			gameTable->setCellsCount(Vector2u((unsigned int)*gameMode, (unsigned int)*gameMode));
			gameTable->randomize();


			*stepsInt = 0;
			steps->setText(to_wstring(*stepsInt));

			solvedMenu->setActive(false);
			gameMenu->setActive(true);
		});
	}
#pragma endregion

#pragma region Steps
	{
		ShadowLabel *label = new ShadowLabel();
		label->setWindow(window);
		label->setFont(*font);
		label->setParent(solvedMenu);
		label->setText(L"ÕÎÄÛ");
		label->setFillColor(FOREGROUND_COLOR);
		label->setPivot(Vector2f(0.5, 1));
		label->setGlobalPosition(Vector2f(250, 590));
		label->setFontSize(32U);
		label->setShadowColor(SHADOW_COLOR);
		label->setShadowOffset(Vector2f(0, 3));
		objects.push_front(label);
	}

	{
		solvedSteps->setWindow(window);
		solvedSteps->setFont(*font);
		solvedSteps->setParent(solvedMenu);
		solvedSteps->setText(L"0");
		solvedSteps->setFillColor(FOREGROUND_COLOR);
		solvedSteps->setPivot(Vector2f(0.5, 0));
		solvedSteps->setGlobalPosition(Vector2f(250, 600));
		solvedSteps->setFontSize(48U);
		solvedSteps->setShadowColor(SHADOW_COLOR);
		solvedSteps->setShadowOffset(Vector2f(0, 4));
		objects.push_front(solvedSteps);
	}

#pragma endregion

#pragma endregion

#pragma region MainMenu
#pragma region playButton
	{
		ShadowBorderLabelButton* button = new ShadowBorderLabelButton();
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
		button->setNormalColor(SHADOW_COLOR);
		button->setFocusedColor(FOCUSED_COLOR);
		button->setPressedColor(FOCUSED_COLOR);
		button->setNormalOffset(Vector2f(0, 3));
		button->setPressedOffsetDl(Vector2f(0, -2));
		objects.push_front(button);

		button->setClick([gameMenu, mainMenu, gameTable, gameMode, stepsInt, steps](UIObject &sender, Mouse::Button button) {
			gameTable->setCellsCount(Vector2u((unsigned int)*gameMode, (unsigned int)*gameMode));
			gameTable->randomize();


			*stepsInt = 0;
			steps->setText(to_wstring(*stepsInt));

			mainMenu->setActive(false);
			gameMenu->setActive(true);
		});
	}
#pragma endregion

#pragma region modeChosing
	{
		GAME_MODES* lbuttonMode = new GAME_MODES(GAME_MODES::EASY);
		GAME_MODES* rbuttonMode = new GAME_MODES(GAME_MODES::HARD);

		ShadowBorderLabelButton *rbutton, *lbutton;
		BorderLabelButton *cbutton;

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
		lbutton = new ShadowBorderLabelButton();
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
		lbutton->setNormalColor(SHADOW_COLOR);
		lbutton->setFocusedColor(FOCUSED_COLOR);
		lbutton->setPressedColor(FOCUSED_COLOR);
		lbutton->setNormalOffset(Vector2f(0, 3));
		lbutton->setPressedOffsetDl(Vector2f(0, -2));
		objects.push_front(lbutton);

		lbutton->setClick([lbutton, cbutton, lbuttonMode, gameMode](UIObject &sender, Mouse::Button button) {
			GAME_MODES tmp = *lbuttonMode;
			*lbuttonMode = *gameMode;
			*gameMode = tmp;

			lbutton->setText(to_wstring((int)*lbuttonMode) + L"x" + to_wstring((int)*lbuttonMode));
			cbutton->setText(to_wstring((int)*gameMode) + L"x" + to_wstring((int)*gameMode));
		});

#pragma endregion
#pragma region rightButton
		rbutton = new ShadowBorderLabelButton();
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
		rbutton->setNormalColor(SHADOW_COLOR);
		rbutton->setFocusedColor(FOCUSED_COLOR);
		rbutton->setPressedColor(FOCUSED_COLOR);
		rbutton->setNormalOffset(Vector2f(0, 3));
		rbutton->setPressedOffsetDl(Vector2f(0, -2));
		objects.push_front(rbutton);

		rbutton->setClick([rbutton, cbutton, rbuttonMode, gameMode](UIObject &sender, Mouse::Button button) {
			GAME_MODES tmp = *rbuttonMode;
			*rbuttonMode = *gameMode;
			*gameMode = tmp;

			rbutton->setText(to_wstring((int)*rbuttonMode) + L"x" + to_wstring((int)*rbuttonMode));
			cbutton->setText(to_wstring((int)*gameMode) + L"x" + to_wstring((int)*gameMode));
		});
#pragma endregion
	}
#pragma endregion

#pragma region Table
	{
		StringTable *table = new StringTable();
		table->setWindow(window);
		table->setPivot(Vector2f(0.5, 0.5));
		table->setFillColor(FOREGROUND_COLOR);
		table->setOutlineColor(FOREGROUND_COLOR);
		table->setOutlineThickness(5);
		table->setSize(Vector2f(304, 304));
		table->setGlobalPosition(Vector2f(250, 330));
		table->setCellsCount(Vector2u(3, 3));
		table->setParent(mainMenu);
		table->setText(new wstring[8]{ L"Ï", L"ß", L"Ò", L"Í", L"À", L"Ø", L"Ê", L"È" }, 8);
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
	solvedMenu->setActive(false);
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
			obj->render();
		}
		window.display();
	}

	return 0;
}