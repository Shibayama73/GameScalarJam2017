//============================================================//
//*名　前	PlayScene.cpp
//*内　容	ゲームプレイシーン
//*日　付	2017.7.13
//*更　新	2017.7.13
//*制作者	N.Shibayama
//============================================================//
#include "PlayScene.h"
#include <WICTextureLoader.h>

using namespace DirectX;
using namespace DirectX::SimpleMath;
using Microsoft::WRL::ComPtr;

PlayScene::PlayScene(int width, int height) :m_outputWidth(width), m_outputHeight(height)
{
}

int PlayScene::InitializeGame()
{
	auto& devices = Devices::GetInstance();
	auto& key = Keyboards::GetInstance();

	//	スプライトバッチ生成
	this->m_spriteBatch = std::make_unique<SpriteBatch>(devices.GetDeviceContext().Get());
	//	グリッド生成
	//	this->m_gridFloor = std::make_unique<GridFloor>(20.0f,20);
	//	フォント生成
	this->m_spriteFont = std::make_unique<SpriteFont>(devices.GetDevice().Get(), L"myfile.spritefont");
	//	コモンステート生成する
	this->m_commonStates = std::make_unique<CommonStates>(devices.GetDevice().Get());
	//	エフェクトファクトリ生成
	//this->m_effectFactory = std::make_unique<EffectFactory>(devices.GetDevice().Get());
	this->m_effect = std::make_unique<BasicEffect>(devices.GetDevice().Get());
	this->m_effect->SetProjection(XMMatrixOrthographicOffCenterRH(0, m_outputWidth, m_outputHeight, 0, 0, 1));
	this->m_effect->SetVertexColorEnabled(true);
	void const* shaderByteCode;
	size_t byteCodeLength;
	this->m_effect->GetVertexShaderBytecode(&shaderByteCode, &byteCodeLength);

	//	リソース読み込み
	ComPtr<ID3D11Resource> resource;
	DX::ThrowIfFailed(
		CreateWICTextureFromFile(devices.GetDevice().Get(), L"Resources/clear.png", resource.GetAddressOf(),
			m_texture.ReleaseAndGetAddressOf()));

	//	20個の部屋の生成
	for (int j = 0; j < 4; j++)
	{
		for (int k = 0; k < 5; k++)
		{
			mapRoom[j*5+k] = new MapRoom(j, k);
		}
	}

	for (int i = 0; i < 20; i++)
	{
		mapRoom[i]->Initialize();
	}

	return 0;
}

int PlayScene::UpdateGame()
{
	return 0;
}

void PlayScene::RenderGame()
{
	//this->m_spriteBatch->Begin();
	//this->m_spriteFont->DrawString(m_spriteBatch.get(), L"COUNT", SimpleMath::Vector2(0, 50), Colors::Blue, 0, Vector3(0, 0, 0), Vector3(2, 2, 2));

	auto& devices = Devices::GetInstance();

	//	テクスチャの描画
	CommonStates m_states(devices.GetDevice().Get());
	m_spriteBatch->Begin(SpriteSortMode_Deferred, m_states.NonPremultiplied());
	//	クリアー
	//m_spriteBatch->Draw(m_texture.Get(), Vector2(263.5f, 324.0f), nullptr, Colors::White, 0.0f);
	
	for (int i = 0; i < 20; i++)
	{
		//	マップ部屋
		mapRoom[i]->Draw(&*m_spriteBatch);
	}

	this->m_spriteBatch->End();
}

void PlayScene::Finalize()
{
	for (int i = 0; i < 20; i++)
	{
		delete mapRoom[i];
	}
}
