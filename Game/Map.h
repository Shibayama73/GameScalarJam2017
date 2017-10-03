//============================================================//
//*名　前	Map.h
//*内　容	マップ
//*日　付	2017.9.30
//*更　新	2017.9.30
//*制作者	N.Shibayama
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

	//	一部屋の地形状態取得
	MapRoom* Get1Room(int height, int width);
	//	一部屋の地形存在有無
	bool Is1RoomTile(int height, int width);

private:
	int m_heightNum;
	int m_widthNum;

	//	マップ部屋
	MapRoom* m_mapRoom[4][5];

};
