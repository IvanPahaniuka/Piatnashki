#include "Effect.h"

using namespace std;

namespace UI
{
	Effect::Effect()
	{
	}

	Effect::Effect(UIObject & target)
	{
		this->target = &target;
		target.effectAdd(*this);
	}

	void Effect::setTarget(UIObject *target)
	{
		if (this->target != nullptr)
			this->target->effects.remove(this);
		
		this->target = target;

		if (target != nullptr)
			target->effectAdd(*this);
	}

	UIObject* Effect::getTarget()
	{
		return target;
	}

	void Effect::drawTarget()
	{
		if (target != nullptr)
			if (target->getActive())
				target->draw();
	}

	Effect::~Effect()
	{
	}
}
