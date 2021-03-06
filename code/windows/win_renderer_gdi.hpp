#pragma once

#include "win_internal.hpp"
#include "../common/data.hpp"
#include <windows.h>

namespace Windows
{
	inline Quad rect_to_quad(RECT rect)
	{
		Quad quad;
		quad.position.x = rect.left;
		quad.position.y = rect.top;
		quad.size.x     = rect.right  - rect.left;
		quad.size.y     = rect.bottom - rect.top;
		return quad;
	}

	inline RECT quad_to_rect(Quad quad)
	{
		RECT rect;
		rect.left   = quad.position.x;
		rect.top    = quad.position.y;
		rect.right  = quad.position.x + quad.size.x;
		rect.bottom = quad.position.y + quad.size.y;
		return rect;
	}

	class GDIRenderer : public Submodule
	{
	public:
		GDIRenderer(Internal&);
		void init();
		void cleanup();
		void handle_paint_msg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		void begin_rendering(HWND hWnd);
		void end_rendering(HWND hWnd);
		void draw_quad(const Quad&, const Colour&);
	private:
		HDC hDC;
	};
}
// namespace Windows
