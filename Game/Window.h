#pragma once

//#include "GameMain.h"
#include <d3d11_1.h>
#include <Mouse.h>
#include <keyboard.h>

#include "Game.h"


class Window
{
public:
	Window(HINSTANCE hInstance,int nCmdShow):hInstance(hInstance),nCmdShow(nCmdShow){}

	//	初期化
	int Initialize(int width, int height);

	HWND HWnd() { return this->hWnd; }

	//	ウィンドウプロシージャ
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	HWND hWnd;
	HINSTANCE hInstance;
	int nCmdShow;


};