//============================================================//
//*���@�O	Map.h
//*���@�e	�}�b�v
//*���@�t	2017.9.30
//*�X�@�V	2017.9.30
//*�����	N.Shibayama
//============================================================//
#pragma once
#include "MapRoom.h"
#include <SpriteBatch.h>
#include <simplemath.h>

class Map 
{
public:
	Map();
	int Initialize();
	int Draw(DirectX::SpriteBatch* spriteBatch);
	void Finalize();

	//	�ꕔ���̒n�`��Ԏ擾
	MapRoom* Get1Room(int height, int width);
	//	�ꕔ���̒n�`���ݗL��
	bool Is1RoomTile(int height, int width);

private:
	int m_heightNum;
	int m_widthNum;

	//	�}�b�v����
	MapRoom* m_mapRoom[4][5];

};
