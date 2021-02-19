#pragma once

#include "win_submodule.hpp"

namespace Windows
{
	class System : public Submodule
	{
	public:
		System(Internal&);
		void init();
		void quit();
	};
}
// namespace Windows
