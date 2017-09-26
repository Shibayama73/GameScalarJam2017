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

	//	�Q�[�����[�v�̎��s
	//MSG Run();
	void Run();

    // Basic game loop
    //void Tick();

	//	�I������
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
	//	�C���X�^���X�n���h��
	HINSTANCE hInstance;
	//	���s���̃E�B���h�E�̑傫��
	int nCmdShow;

	//	�f�o�C�X���\�[�X.
	HWND hWnd;
	//	�o�͕�
	int m_outputWidth;
	//	�o�͍���
	int m_outputHeight;
	//	���x��
	D3D_FEATURE_LEVEL m_featureLevel;
	// Rendering loop timer.
	DX::StepTimer m_timer;
	//	�f�o�C�X
	std::unique_ptr<Devices> devices;
	//	�E�B���h�E
	std::unique_ptr<Window> m_window;
	////	�L�[�{�[�h
	//std::unique_ptr<DirectX::Keyboard> m_keyboard;
//	//	�X�v���C�g�o�b�`
//	std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
//	//	�f�o�b�O�J����
////	std::unique_ptr<DebugCamera> m_debugCamera;
//	Camera* m_camera;
//	//	�O���b�h�t���A
////	std::unique_ptr<GridFloor> m_gridFloor;
//	//	�t�H���g
//	std::unique_ptr<DirectX::SpriteFont> m_spriteFont;
//	//	�G�t�F�N�g�t�@�N�g��
////	std::unique_ptr<DirectX::IEffectFactory> m_effectFactory;
//	std::unique_ptr<DirectX::BasicEffect> m_effect;
//	//	�R�����X�e�[�g
//	std::unique_ptr<DirectX::CommonStates> m_commonStates;
//	//	���f��
//	//std::unique_ptr<DirectX::Model> m_model;
//	Object3D m_model;
//	//	���[���h
//	DirectX::SimpleMath::Matrix m_world;
//	//	�X�P�[��
//	float m_scale;

//	std::unique_ptr<DirectX::GeometricPrimitive> box;

};
