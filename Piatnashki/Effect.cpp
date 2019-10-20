#include "Effect.h"

using namespace std;

namespace UI
{
	Effect::Effect(UIObject & target)
	{
		this->target = &target;
		target.effectAdd(*this);
	}

	UIObject* Effect::getTarget()
	{
		return target;
	}

	void Effect::drawTarget()
	{
		target->draw();
	}

	Effect::~Effect()
	{
		target->effectRemove(*this);
	}
}
