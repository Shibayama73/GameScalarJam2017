//============================================================//
//*名　前	PlayScene.h
//*内　容	ゲームプレイシーン
//*日　付	2017.7.13
//*更　新	2017.7.13
//*制作者	N.Shibayama
//============================================================//
#pragma once
#include "SceneBase.h"
#include "Devices.h"
#include <SpriteBatch.h>
#include <SpriteFont.h>
#include <Effects.h>
#include <CommonStates.h>
//#include <keyboard.h>
#include "Keyboards.h"
#include "MapRoom.h"

class PlayScene :public SceneBase
{
public:
	PlayScene(int width,int height);
	int InitializeGame();
	int UpdateGame();
	void RenderGame();
	void Finalize();

private:
	//	出力幅
	int m_outputWidth;
	//	出力高さ
	int m_outputHeight;

	//	キーボード
//	std::unique_ptr<DirectX::Keyboard> m_keyboard;
	//	トラッカー
//	std::unique_ptr<DirectX::Keyboard::KeyboardStateTracker> m_tracker;

	//	スプライトバッチ
	std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
	//	フォント
	std::unique_ptr<DirectX::SpriteFont> m_spriteFont;
	//	エフェクトファクトリ
	std::unique_ptr<DirectX::BasicEffect> m_effect;
	//	コモンステート
	std::unique_ptr<DirectX::CommonStates> m_commonStates;

	//	クリアーテクスチャ
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;


	DirectX::SimpleMath::Matrix m_view;
	DirectX::SimpleMath::Matrix m_proj;

	MapRoom* mapRoom;

};
