//============================================================//
//*名　前	GameMain.h
//*内　容	メイン(軸となるところ)
//*日　付	2017.7.13
//*更　新	2017.7.13
//*制作者	N.Shibayama
//============================================================//
#pragma once
#include "Game.h"
#include "SceneBase.h"

class Game;

class GameMain :public Game
{
public:
	enum Scene
	{
		LOGO,
		TITLE,
		PLAY,
		RESULT,
	};

public:
	GameMain(int width, int height);

	//	初期化
	int Initialize();
	//	画面サイズ取得
	void GetDefaultSize(int& width, int& height);
	//	作動
	void Tick();

	//	更新
	void Update();
	//	描画
	void Render();

private:
	//std::unique_ptr<Game> m_game;
	Game* m_game;
	//std::unique_ptr<SceneBase> m_sceneBase;
	SceneBase* m_sceneBase;

};
