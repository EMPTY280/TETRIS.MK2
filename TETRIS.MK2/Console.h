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

	// �ܼ� ȭ�� Ŭ����
	void Clear();

	// Ŀ�� ��ġ ����
	void Move(int x, int y);
	void Move(COORD pos);

	// ��� ���� ����
	void SetColor(Color color);

	// Ŀ�� �����
	void HideCursor();
}