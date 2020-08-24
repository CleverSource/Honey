#pragma once

namespace Honey
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0                = 0,
		Button1                = 1,
		Button2                = 2,
		Button3                = 3,
		Button4                = 4,
		Button5                = 5,
		Button6                = 6,
		Button7                = 7,

		ButtonLast             = Button7,
		ButtonLeft             = Button0,
		ButtonRight            = Button1,
		ButtonMiddle           = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define HN_MOUSE_BUTTON_0      ::Honey::Mouse::Button0
#define HN_MOUSE_BUTTON_1      ::Honey::Mouse::Button1
#define HN_MOUSE_BUTTON_2      ::Honey::Mouse::Button2
#define HN_MOUSE_BUTTON_3      ::Honey::Mouse::Button3
#define HN_MOUSE_BUTTON_4      ::Honey::Mouse::Button4
#define HN_MOUSE_BUTTON_5      ::Honey::Mouse::Button5
#define HN_MOUSE_BUTTON_6      ::Honey::Mouse::Button6
#define HN_MOUSE_BUTTON_7      ::Honey::Mouse::Button7
#define HN_MOUSE_BUTTON_LAST   ::Honey::Mouse::ButtonLast
#define HN_MOUSE_BUTTON_LEFT   ::Honey::Mouse::ButtonLeft
#define HN_MOUSE_BUTTON_RIGHT  ::Honey::Mouse::ButtonRight
#define HN_MOUSE_BUTTON_MIDDLE ::Honey::Mouse::ButtonMiddle