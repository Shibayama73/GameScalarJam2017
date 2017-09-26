//============================================================//
//*名　前	MapRoom.h
//*内　容	マップ部屋生成
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
	MapRoom();
	int Initialize(int width, int height);
	int Update();
	int Draw(DirectX::SpriteBatch* spriteBatch);

private:
	int m_height;	//1部屋の高さ
	int m_width;	//1部屋の幅
	int m_room[20];	//部屋の数

	//	大枠テクスチャ
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
	//	描画位置
	DirectX::SimpleMath::Vector2 m_screenPos;
	
	//	ウィンドウの大きさ
	int m_outputWidth;
	int m_outputHeight;

};
