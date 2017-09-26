//
// Game.h
//

#pragma once

#include <d3d11_1.h>
#include <SpriteBatch.h>
#include <SpriteFont.h>
#include <Effects.h>
#include <CommonStates.h>
#include <Model.h>
#include <GeometricPrimitive.h>
#include <keyboard.h>

#include "StepTimer.h"
#include "Window.h"
#include "Devices.h"

class Window;

// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:
	Game(int width, int height);

    // Initialization and management
    void Initialize();

	void Render();
	void Clear();
	void Present();

	//	ゲームループの実行
	//MSG Run();
	void Run();

    // Basic game loop
    //void Tick();

	//	終了する
	void Finalize();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize(int& width, int& height ) const;

private:
    void Update(DX::StepTimer const& timer);

    
	void DrawFPS();

private:
	//	インスタンスハンドル
	HINSTANCE hInstance;
	//	実行時のウィンドウの大きさ
	int nCmdShow;

	//	デバイスリソース.
	HWND hWnd;
	//	出力幅
	int m_outputWidth;
	//	出力高さ
	int m_outputHeight;
	//	レベル
	D3D_FEATURE_LEVEL m_featureLevel;
	// Rendering loop timer.
	DX::StepTimer m_timer;
	//	デバイス
	std::unique_ptr<Devices> devices;
	//	ウィンドウ
	std::unique_ptr<Window> m_window;
	////	キーボード
	//std::unique_ptr<DirectX::Keyboard> m_keyboard;
//	//	スプライトバッチ
//	std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
//	//	デバッグカメラ
////	std::unique_ptr<DebugCamera> m_debugCamera;
//	Camera* m_camera;
//	//	グリッドフロア
////	std::unique_ptr<GridFloor> m_gridFloor;
//	//	フォント
//	std::unique_ptr<DirectX::SpriteFont> m_spriteFont;
//	//	エフェクトファクトリ
////	std::unique_ptr<DirectX::IEffectFactory> m_effectFactory;
//	std::unique_ptr<DirectX::BasicEffect> m_effect;
//	//	コモンステート
//	std::unique_ptr<DirectX::CommonStates> m_commonStates;
//	//	モデル
//	//std::unique_ptr<DirectX::Model> m_model;
//	Object3D m_model;
//	//	ワールド
//	DirectX::SimpleMath::Matrix m_world;
//	//	スケール
//	float m_scale;

//	std::unique_ptr<DirectX::GeometricPrimitive> box;

};
