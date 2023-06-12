#pragma once

#include <Windows.h>

namespace Console
{
	enum class Color
	{
		BLACK,
		DARK_BLUE,
		DARK_GREEN,
		DARK_SKYBLUE,
		DARK_RED,
		DARK_VOILET,
		DAKR_YELLOW,
		GRAY,
		DARK_GRAY,
		BLUE,
		GREEN,
		SKYBLUE,
		RED,
		VIOLET,
		YELLOW,
		WHITE
	};

	// 콘솔 화면 클리어
	void Clear();

	// 커서 위치 변경
	void Move(int x, int y);
	void Move(COORD pos);

	// 출력 색상 지정
	void SetColor(Color color);

	// 커서 숨기기
	void HideCursor();
}