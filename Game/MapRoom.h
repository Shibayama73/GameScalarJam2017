//============================================================//
//*名　前	MapRoom.h
//*内　容	マップ1部屋生成
//*日　付	2017.9.26
//*更　新	2017.9.26
//*制作者	N.Shibayama
//============================================================//
#pragma once
#include <SpriteBatch.h>
#include <simplemath.h>

class MapRoom
{
public:
	MapRoom(int heightNum, int widthNum);
	int Initialize();
	int Update();
	int Draw(DirectX::SpriteBatch* spriteBatch);

	//	一部屋の地形状態取得
	int Get1RoomTile(int height,int width);
	//	地形生成時の軸の高さ取得
	int GetTileAxisHeight();
	//	地形生成時の軸の幅取得
	int GetTileAxisWidth();
	//	地形の存在有無
	bool IsTileExistence();

private:
	int m_roomHeight;	//1部屋の高さ
	int m_roomWidth;	//1部屋の幅
	int m_room[5][5];	//1部屋の数

	struct Tile{
		//	地形生成時の軸の高さ
		int axisHeight;
		//	地形生成時の軸の幅
		int axisWidth;
	};

	Tile m_tile;

	//	1部屋の中の小分けされたテクスチャ
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
	//	描画位置
	DirectX::SimpleMath::Vector2 m_screenPos;
	
	//	部屋の位置
	int m_widthNum;
	int m_heightNum;

	//	地形の存在有無
	bool m_existence;

};
