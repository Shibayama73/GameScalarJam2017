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

private:
	int m_roomHeight;	//1部屋の高さ
	int m_roomWidth;	//1部屋の幅
	static int m_room[5][5];	//1部屋の数

	//	1部屋の中の小分けされたテクスチャ
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
	//	描画位置
	DirectX::SimpleMath::Vector2 m_screenPos;
	
	//	部屋の位置
	int m_widthNum;
	int m_heightNum;

	//	ウィンドウの大きさ
	//int m_outputWidth;
	//int m_outputHeight;

	//	存在する(透明ではない)
	//bool IsPellucidity;

};
