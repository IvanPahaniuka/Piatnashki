#pragma once
#include <SFML/Graphics.hpp>
#include <forward_list>
#include <functional>
#include "Object.h"



using namespace sf;
using namespace std;


namespace UI 
{
	class UIObject: public Object
	{
		friend class Effect;

	public:
		typedef function<void(UIObject &sender)> MouseMovingFunc;
		typedef function<void(UIObject &sender, Mouse::Button button)> MousePressingFunc;

		UIObject();

		virtual void update() {};

		void render();

		RenderWindow* getWindow();
		virtual void setWindow(RenderWindow &window);

		virtual void setPivot(Vector2f pivot);
		Vector2f getPivot();

		virtual void setFillColor(Color fillColor) {};
		virtual Color getFillColor();

		virtual void setOutlineColor(Color outlineColor) {};
		virtual Color getOutlineColor();

		virtual void setOutlineThickness(float thickness) {};
		virtual float getOutlineThickness();
		
		~UIObject() {};

	protected:
		virtual void draw() {};
		virtual void updatePivot() {};


		void effectAdd(Effect &effect);
		void effectRemove(Effect &effect);



	private:
		RenderWindow* window = nullptr;
		Vector2f pivot = Vector2f(0.5, 0.5);
		forward_list<Effect*> effects;
	};
}

