#pragma once

namespace Honey
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space               = 32,
		Apostrophe          = 39, /* ' */
		Comma               = 44, /* , */
		Minus               = 45, /* - */
		Period              = 46, /* . */
		Slash               = 47, /* / */

		D0                  = 48, /* 0 */
		D1                  = 49, /* 1 */
		D2                  = 50, /* 2 */
		D3                  = 51, /* 3 */
		D4                  = 52, /* 4 */
		D5                  = 53, /* 5 */
		D6                  = 54, /* 6 */
		D7                  = 55, /* 7 */
		D8                  = 56, /* 8 */
		D9                  = 57, /* 9 */

		Semicolon           = 59, /* ; */
		Equal               = 61, /* = */

		A                   = 65,
		B                   = 66,
		C                   = 67,
		D                   = 68,
		E                   = 69,
		F                   = 70,
		G                   = 71,
		H                   = 72,
		I                   = 73,
		J                   = 74,
		K                   = 75,
		L                   = 76,
		M                   = 77,
		N                   = 78,
		O                   = 79,
		P                   = 80,
		Q                   = 81,
		R                   = 82,
		S                   = 83,
		T                   = 84,
		U                   = 85,
		V                   = 86,
		W                   = 87,
		X                   = 88,
		Y                   = 89,
		Z                   = 90,

		LeftBracket         = 91,  /* [ */
		Backslash           = 92,  /* \ */
		RightBracket        = 93,  /* ] */
		GraveAccent         = 96,  /* ` */

		World1              = 161, /* non-US #1 */
		World2              = 162, /* non-US #2 */

		/* Function keys */
		Escape              = 256,
		Enter               = 257,
		Tab                 = 258,
		Backspace           = 259,
		Insert              = 260,
		Delete              = 261,
		Right               = 262,
		Left                = 263,
		Down                = 264,
		Up                  = 265,
		PageUp              = 266,
		PageDown            = 267,
		Home                = 268,
		End                 = 269,
		CapsLock            = 280,
		ScrollLock          = 281,
		NumLock             = 282,
		PrintScreen         = 283,
		Pause               = 284,
		F1                  = 290,
		F2                  = 291,
		F3                  = 292,
		F4                  = 293,
		F5                  = 294,
		F6                  = 295,
		F7                  = 296,
		F8                  = 297,
		F9                  = 298,
		F10                 = 299,
		F11                 = 300,
		F12                 = 301,
		F13                 = 302,
		F14                 = 303,
		F15                 = 304,
		F16                 = 305,
		F17                 = 306,
		F18                 = 307,
		F19                 = 308,
		F20                 = 309,
		F21                 = 310,
		F22                 = 311,
		F23                 = 312,
		F24                 = 313,
		F25                 = 314,

		/* Keypad */
		KP0                 = 320,
		KP1                 = 321,
		KP2                 = 322,
		KP3                 = 323,
		KP4                 = 324,
		KP5                 = 325,
		KP6                 = 326,
		KP7                 = 327,
		KP8                 = 328,
		KP9                 = 329,
		KPDecimal           = 330,
		KPDivide            = 331,
		KPMultiply          = 332,
		KPSubtract          = 333,
		KPAdd               = 334,
		KPEnter             = 335,
		KPEqual             = 336,

		LeftShift           = 340,
		LeftControl         = 341,
		LeftAlt             = 342,
		LeftSuper           = 343,
		RightShift          = 344,
		RightControl        = 345,
		RightAlt            = 346,
		RightSuper          = 347,
		Menu                = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define HN_KEY_SPACE           ::Honey::Key::Space
#define HN_KEY_APOSTROPHE      ::Honey::Key::Apostrophe    /* ' */
#define HN_KEY_COMMA           ::Honey::Key::Comma         /* , */
#define HN_KEY_MINUS           ::Honey::Key::Minus         /* - */
#define HN_KEY_PERIOD          ::Honey::Key::Period        /* . */
#define HN_KEY_SLASH           ::Honey::Key::Slash         /* / */
#define HN_KEY_0               ::Honey::Key::D0
#define HN_KEY_1               ::Honey::Key::D1
#define HN_KEY_2               ::Honey::Key::D2
#define HN_KEY_3               ::Honey::Key::D3
#define HN_KEY_4               ::Honey::Key::D4
#define HN_KEY_5               ::Honey::Key::D5
#define HN_KEY_6               ::Honey::Key::D6
#define HN_KEY_7               ::Honey::Key::D7
#define HN_KEY_8               ::Honey::Key::D8
#define HN_KEY_9               ::Honey::Key::D9
#define HN_KEY_SEMICOLON       ::Honey::Key::Semicolon     /* ; */
#define HN_KEY_EQUAL           ::Honey::Key::Equal         /* = */
#define HN_KEY_A               ::Honey::Key::A
#define HN_KEY_B               ::Honey::Key::B
#define HN_KEY_C               ::Honey::Key::C
#define HN_KEY_D               ::Honey::Key::D
#define HN_KEY_E               ::Honey::Key::E
#define HN_KEY_F               ::Honey::Key::F
#define HN_KEY_G               ::Honey::Key::G
#define HN_KEY_H               ::Honey::Key::H
#define HN_KEY_I               ::Honey::Key::I
#define HN_KEY_J               ::Honey::Key::J
#define HN_KEY_K               ::Honey::Key::K
#define HN_KEY_L               ::Honey::Key::L
#define HN_KEY_M               ::Honey::Key::M
#define HN_KEY_N               ::Honey::Key::N
#define HN_KEY_O               ::Honey::Key::O
#define HN_KEY_P               ::Honey::Key::P
#define HN_KEY_Q               ::Honey::Key::Q
#define HN_KEY_R               ::Honey::Key::R
#define HN_KEY_S               ::Honey::Key::S
#define HN_KEY_T               ::Honey::Key::T
#define HN_KEY_U               ::Honey::Key::U
#define HN_KEY_V               ::Honey::Key::V
#define HN_KEY_W               ::Honey::Key::W
#define HN_KEY_X               ::Honey::Key::X
#define HN_KEY_Y               ::Honey::Key::Y
#define HN_KEY_Z               ::Honey::Key::Z
#define HN_KEY_LEFT_BRACKET    ::Honey::Key::LeftBracket   /* [ */
#define HN_KEY_BACKSLASH       ::Honey::Key::Backslash     /* \ */
#define HN_KEY_RIGHT_BRACKET   ::Honey::Key::RightBracket  /* ] */
#define HN_KEY_GRAVE_ACCENT    ::Honey::Key::GraveAccent   /* ` */
#define HN_KEY_WORLD_1         ::Honey::Key::World1        /* non-US #1 */
#define HN_KEY_WORLD_2         ::Honey::Key::World2        /* non-US #2 */

/* Function keys */
#define HN_KEY_ESCAPE          ::Honey::Key::Escape
#define HN_KEY_ENTER           ::Honey::Key::Enter
#define HN_KEY_TAB             ::Honey::Key::Tab
#define HN_KEY_BACKSPACE       ::Honey::Key::Backspace
#define HN_KEY_INSERT          ::Honey::Key::Insert
#define HN_KEY_DELETE          ::Honey::Key::Delete
#define HN_KEY_RIGHT           ::Honey::Key::Right
#define HN_KEY_LEFT            ::Honey::Key::Left
#define HN_KEY_DOWN            ::Honey::Key::Down
#define HN_KEY_UP              ::Honey::Key::Up
#define HN_KEY_PAGE_UP         ::Honey::Key::PageUp
#define HN_KEY_PAGE_DOWN       ::Honey::Key::PageDown
#define HN_KEY_HOME            ::Honey::Key::Home
#define HN_KEY_END             ::Honey::Key::End
#define HN_KEY_CAPS_LOCK       ::Honey::Key::CapsLock
#define HN_KEY_SCROLL_LOCK     ::Honey::Key::ScrollLock
#define HN_KEY_NUM_LOCK        ::Honey::Key::NumLock
#define HN_KEY_PRINT_SCREEN    ::Honey::Key::PrintScreen
#define HN_KEY_PAUSE           ::Honey::Key::Pause
#define HN_KEY_F1              ::Honey::Key::F1
#define HN_KEY_F2              ::Honey::Key::F2
#define HN_KEY_F3              ::Honey::Key::F3
#define HN_KEY_F4              ::Honey::Key::F4
#define HN_KEY_F5              ::Honey::Key::F5
#define HN_KEY_F6              ::Honey::Key::F6
#define HN_KEY_F7              ::Honey::Key::F7
#define HN_KEY_F8              ::Honey::Key::F8
#define HN_KEY_F9              ::Honey::Key::F9
#define HN_KEY_F10             ::Honey::Key::F10
#define HN_KEY_F11             ::Honey::Key::F11
#define HN_KEY_F12             ::Honey::Key::F12
#define HN_KEY_F13             ::Honey::Key::F13
#define HN_KEY_F14             ::Honey::Key::F14
#define HN_KEY_F15             ::Honey::Key::F15
#define HN_KEY_F16             ::Honey::Key::F16
#define HN_KEY_F17             ::Honey::Key::F17
#define HN_KEY_F18             ::Honey::Key::F18
#define HN_KEY_F19             ::Honey::Key::F19
#define HN_KEY_F20             ::Honey::Key::F20
#define HN_KEY_F21             ::Honey::Key::F21
#define HN_KEY_F22             ::Honey::Key::F22
#define HN_KEY_F23             ::Honey::Key::F23
#define HN_KEY_F24             ::Honey::Key::F24
#define HN_KEY_F25             ::Honey::Key::F25

/* Keypad */
#define HN_KEY_KP_0            ::Honey::Key::KP0
#define HN_KEY_KP_1            ::Honey::Key::KP1
#define HN_KEY_KP_2            ::Honey::Key::KP2
#define HN_KEY_KP_3            ::Honey::Key::KP3
#define HN_KEY_KP_4            ::Honey::Key::KP4
#define HN_KEY_KP_5            ::Honey::Key::KP5
#define HN_KEY_KP_6            ::Honey::Key::KP6
#define HN_KEY_KP_7            ::Honey::Key::KP7
#define HN_KEY_KP_8            ::Honey::Key::KP8
#define HN_KEY_KP_9            ::Honey::Key::KP9
#define HN_KEY_KP_DECIMAL      ::Honey::Key::KPDecimal
#define HN_KEY_KP_DIVIDE       ::Honey::Key::KPDivide
#define HN_KEY_KP_MULTIPLY     ::Honey::Key::KPMultiply
#define HN_KEY_KP_SUBTRACT     ::Honey::Key::KPSubtract
#define HN_KEY_KP_ADD          ::Honey::Key::KPAdd
#define HN_KEY_KP_ENTER        ::Honey::Key::KPEnter
#define HN_KEY_KP_EQUAL        ::Honey::Key::KPEqual

#define HN_KEY_LEFT_SHIFT      ::Honey::Key::LeftShift
#define HN_KEY_LEFT_CONTROL    ::Honey::Key::LeftControl
#define HN_KEY_LEFT_ALT        ::Honey::Key::LeftAlt
#define HN_KEY_LEFT_SUPER      ::Honey::Key::LeftSuper
#define HN_KEY_RIGHT_SHIFT     ::Honey::Key::RightShift
#define HN_KEY_RIGHT_CONTROL   ::Honey::Key::RightControl
#define HN_KEY_RIGHT_ALT       ::Honey::Key::RightAlt
#define HN_KEY_RIGHT_SUPER     ::Honey::Key::RightSuper
#define HN_KEY_MENU            ::Honey::Key::Menu