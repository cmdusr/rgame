#pragma once

namespace Windows
{
	class Internal;

	class Submodule
	{
	public:
		Submodule(Internal& in_internal);
	protected:
		Internal* internal;
	};
}
// namespace Windows
