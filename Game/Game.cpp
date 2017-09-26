//
// Game.cpp
//

#include "pch.h"
#include "Game.h"

extern void ExitGame();

using namespace DirectX;
using namespace DirectX::SimpleMath;
using Microsoft::WRL::ComPtr;

Game::Game(int width, int height)
	:hWnd(0),m_outputWidth(width),m_outputHeight(height),m_featureLevel(D3D_FEATURE_LEVEL_9_1)
{
	//	�X�^�[�g�A�b�v���
	STARTUPINFO si{};
	//	�C���X�^���X�擾
	this->hInstance = ::GetModuleHandle(NULL);

	//	StartupInfo�\���̂̓��e�擾
	::GetStartupInfo(&si);
	this->nCmdShow = si.dwFlags & STARTF_USESHOWWINDOW ? si.wShowWindow :
		SW_SHOWDEFAULT;;

	//	�E�B���h�E�I�u�W�F�N�g����
	this->m_window = std::make_unique<Window>(this->hInstance, this->nCmdShow);

	////	�X�P�[��
	//this->m_scale = 1.0f;

}

void Game::Initialize()
{
	//	�E�B���h�E�I�u�W�F�N�g�̏�����
	this->m_window->Initialize(this->m_outputWidth, this->m_outputHeight);
	//	�E�B���h�E�n���h���擾
	this->hWnd = this->m_window->HWnd();
	//	�f�o�C�X�N���X�̃C���X�^���X�擾
	auto& devices = Devices::GetInstance();
	devices.SetHandleWind(this->hWnd);
	devices.SetWidth(this->m_outputWidth);
	devices.SetHeight(this->m_outputHeight);

	//	�f�o�C�X����
	devices.CreateDevice();
	//	���\�[�X����
	devices.CreateResources();

	// TODO: Change the timer settings if you want something other than the default variable timestep mode.
	// e.g. for 60 FPS fixed timestep update logic, call:
	/*
	m_timer.SetFixedTimeStep(true);
	m_timer.SetTargetElapsedSeconds(1.0 / 60);
	*/
	////	�L�[�{�[�h����
	//this->m_keyboard = std::make_unique<Keyboard>();
//	//	�f�o�b�O�J��������
////	this->m_debugCamera = std::make_unique<DebugCamera>(this->m_outputWidth, this->m_outputHeight);
//	//	�J��������
//	this->m_camera = new Camera(this->m_outputWidth,this->m_outputHeight);
//	//	�X�v���C�g�o�b�`����
//	this->m_spriteBatch = std::make_unique<SpriteBatch>(devices.GetDeviceContext().Get());
//	//	�O���b�h����
////	this->m_gridFloor = std::make_unique<GridFloor>(20.0f,20);
//	//	�t�H���g����
//	this->m_spriteFont = std::make_unique<SpriteFont>(devices.GetDevice().Get(),L"myfile.spritefont");
//	//	�R�����X�e�[�g��������
//	this->m_commonStates = std::make_unique<CommonStates>(devices.GetDevice().Get());
//	//	�G�t�F�N�g�t�@�N�g������
////		this->m_effectFactory = std::make_unique<EffectFactory>(devices.GetDevice().Get());
//	this->m_effect = std::make_unique<BasicEffect>(devices.GetDevice().Get());
//	this->m_effect->SetProjection(XMMatrixOrthographicOffCenterRH(0, m_outputWidth, m_outputHeight, 0, 0, 1));
//	this->m_effect->SetVertexColorEnabled(true);
//	void const* shaderByteCode;
//	size_t byteCodeLength;
//	this->m_effect->GetVertexShaderBytecode(&shaderByteCode, &byteCodeLength);
//
//	//	CMO�t�@�C������I�u�W�F�N�g����
//	//this->m_model = Model::CreateFromCMO(devices.GetDevice().Get(), L"cup.cmo", *this->m_effectFactory);
//	//this->m_model.InitializeStatic(m_debugCamera);
//	this->m_model.InitializeStatic(m_camera);
//	this->m_model.LoadModel(L"Resources/Skydome.cmo");

//	this->box = GeometricPrimitive::CreateBox(devices.GetDeviceContext().Get(), XMFLOAT3(10, 10, 10), true, true);


}

void Game::Run()
{
	////	���b�Z�[�W
	//MSG msg = {};

	////	������
	//this->Initialize();
	////	�Q�[�����[�v
	//while (WM_QUIT != msg.message)
	//{
	//	if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	//	{
	//		TranslateMessage(&msg);
	//		DispatchMessage(&msg);
	//	}
	//	else
	//	{
			//	�Q�[���X�V
			this->m_timer.Tick([&]() {this->Update(this->m_timer); });
	//		//	�V�[���`��
	//		this->Render();
	//	}
	//}
	////	�I������
	//this->Finalize();

	//return msg;
}

//// Initialize the Direct3D resources required to run.
//void Game::Initialize(HWND window, int width, int height)
//{
//    this->m_window = window;
//    this->m_outputWidth = std::max(width, 1);
//    this->m_outputHeight = std::max(height, 1);
//
//	//auto& devices = Devices::GetInstance();
//	//devices.SetHandleWind(this->m_window);
//	//devices.SetWidth(this->m_outputWidth);
//	//devices.SetHeight(this->m_outputHeight);
//
//	////	�f�o�C�X����
// //   devices.CreateDevice();
//	////	���\�[�X����
// //   devices.CreateResources();
//
// //   // TODO: Change the timer settings if you want something other than the default variable timestep mode.
// //   // e.g. for 60 FPS fixed timestep update logic, call:
// //   /*
// //   m_timer.SetFixedTimeStep(true);
// //   m_timer.SetTargetElapsedSeconds(1.0 / 60);
// //   */
//}

//// Executes the basic game loop.
//void Game::Tick()
//{
//    m_timer.Tick([&]()
//    {
//        Update(m_timer);
//    });
//
//    Render();
//}

// Updates the world.
void Game::Update(DX::StepTimer const& timer)
{
    float elapsedTime = float(timer.GetElapsedSeconds());

    // TODO: Add your game logic here.
    //elapsedTime;
	//auto keyboard = this->m_keyboard->GetState();

	//if (keyboard.Right)
	//{
	//	//m_scale += 0.1f;
	//}
	//if (keyboard.Left)
	//{
	//	//m_scale -= 0.1f;
	//}

	////	���f���̍X�V
	//this->m_model.Update();

	////	�J�����X�V
	////this->m_debugCamera->Update();
	//this->m_camera->Update();
}

// Draws the scene.
void Game::Render()
{
    // Don't try to render anything before the first Update.
    if (m_timer.GetFrameCount() == 0)
    {
        return;
    }

	//	Clear����Present�̊Ԃɕ`��
 //   Clear();

    // TODO: Add your rendering code here.
//	this->m_spriteBatch->Begin();
//
//	//	�J�����̍X�V
//	//Matrix view = this->m_debugCamera->GetCameraMatrix();
//	Matrix view = this->m_camera->GetViewMatrix();
//	//	�ˉe�s��
//	Matrix projection = Matrix::CreatePerspectiveFieldOfView(DirectX::XMConvertToDegrees(60.0f),
//		(float)this->m_outputWidth / (float)this->m_outputHeight, 1.0f, 100.0f);
//	//	�O���b�h�`��
////	this->m_gridFloor->Render(view, projection);
//	//	FPS�`��
//	this->DrawFPS();
//	//	���[���h�s��̏�����
//	Matrix world = Matrix::Identity;
//	//	�X�P�[���̕ύX
//	world = Matrix::CreateScale(m_scale);
//	//	���f���̕`��
//	//this->m_model->Draw(Devices::GetInstance().GetDeviceContext().Get(), *this->m_commonStates,world, view, projection);
//	this->m_model.Draw();
//
//	this->m_spriteBatch->End();

  //  Present();
}

// Helper method to clear the back buffers.
void Game::Clear()
{
	//	�f�o�C�X�N���X�̃C���X�^���X�擾
	auto& devices = Devices::GetInstance();
    // Clear the views.
	//devices.GetDeviceContext()->ClearRenderTargetView(devices.GetRenderTargetView().Get(), Colors::CornflowerBlue);
	devices.GetDeviceContext()->ClearRenderTargetView(devices.GetRenderTargetView().Get(), Colors::DeepSkyBlue);
    devices.GetDeviceContext()->ClearDepthStencilView(devices.GetDepthStencilView().Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

    devices.GetDeviceContext()->OMSetRenderTargets(1, devices.GetRenderTargetView().GetAddressOf(), devices.GetDepthStencilView().Get());

    // Set the viewport.
    CD3D11_VIEWPORT viewport(0.0f, 0.0f, static_cast<float>(m_outputWidth), static_cast<float>(m_outputHeight));
    devices.GetDeviceContext()->RSSetViewports(1, &viewport);
}

// Presents the back buffer contents to the screen.
void Game::Present()
{
    // The first argument instructs DXGI to block until VSync, putting the application
    // to sleep until the next VSync. This ensures we don't waste any cycles rendering
    // frames that will never be displayed to the screen.
	//	�f�o�C�X�N���X�̃C���X�^���X�擾
	auto& devices = Devices::GetInstance();
	HRESULT hr = devices.GetSwapChain()->Present(1, 0);

    // If the device was reset we must completely reinitialize the renderer.
    if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET)
    {
		devices.OnDeviceLost();
    }
    else
    {
        DX::ThrowIfFailed(hr);
    }
}

void Game::DrawFPS()
{
	//	FPS�����񐶐�
	std::wstring fpsString = L"fps = " + std::to_wstring((unsigned int)this->m_timer.GetFramesPerSecond());
	//	FPS�`��
//	this->m_spriteFont->DrawString(m_spriteBatch.get(), fpsString.c_str(), SimpleMath::Vector2(0, 0), Colors::White);
}

void Game::Finalize()
{
	//	�f�o�C�X�I�u�W�F�N�g�폜
	Devices::Dispose();
	//	�E�B���h�E�I�u�W�F�N�g�폜
	m_window.reset();
}

// Message handlers
void Game::OnActivated()
{
    // TODO: Game is becoming active window.
}

void Game::OnDeactivated()
{
    // TODO: Game is becoming background window.
}

void Game::OnSuspending()
{
    // TODO: Game is being power-suspended (or minimized).
}

void Game::OnResuming()
{
    m_timer.ResetElapsedTime();

    // TODO: Game is being power-resumed (or returning from minimize).
}

void Game::OnWindowSizeChanged(int width, int height)
{
    m_outputWidth = std::max(width, 1);
    m_outputHeight = std::max(height, 1);

    Devices::GetInstance().CreateResources();

    // TODO: Game window is being resized.
}

// Properties
void Game::GetDefaultSize(int& width, int& height) const
{
    // TODO: Change to desired default window size (note minimum size is 320x200).
    width = 800;
    height = 600;
}

void ExitGame() {
	PostQuitMessage(0);
}
