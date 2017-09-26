//============================================================//
//*���@�O	GameMain.h
//*���@�e	���C��(���ƂȂ�Ƃ���)
//*���@�t	2017.7.13
//*�X�@�V	2017.7.13
//*�����	N.Shibayama
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

	//	������
	int Initialize();
	//	��ʃT�C�Y�擾
	void GetDefaultSize(int& width, int& height);
	//	�쓮
	void Tick();

	//	�X�V
	void Update();
	//	�`��
	void Render();

private:
	//std::unique_ptr<Game> m_game;
	Game* m_game;
	//std::unique_ptr<SceneBase> m_sceneBase;
	SceneBase* m_sceneBase;

};
