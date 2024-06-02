#pragma once

namespace Feature
{
	class Aimbot : public Callback
	{
	public:
		Aimbot() : Callback(XOR("Feature Runtime")) {}

		void Invoker() override
		{

		}
	};
	SINGLETON_ACTIVATE_FAST(Aimbot);
}