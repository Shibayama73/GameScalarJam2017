//============================================================//
//*名　前	Player.h
//*内　容	プレイヤー
//*日　付	2017.9.29
//*更　新	2017.9.29
//*制作者	N.Shibayama
//============================================================//
#pragma once
#include <SpriteBatch.h>
#include <simplemath.h>
#include "Devices.h"
#include "MapRoom.h"
#include "Keyboards.h"

class Player
{
public:
	Player(MapRoom* mapRoom);
	int Initialize();
	int Update();
	int Draw(DirectX::SpriteBatch* spriteBatch);

private:
	//	テクスチャ
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
	//	テクスチャ1マス分の幅
	int m_width;
	//	テクスチャ1マス分の高さ
	int m_height;

	//	位置
	int m_position[20][25];

	//	マップ部屋
	MapRoom* m_mapRoom;
};
