//============================================================//
//*���@�O	PlayScene.h
//*���@�e	�Q�[���v���C�V�[��
//*���@�t	2017.7.13
//*�X�@�V	2017.7.13
//*�����	N.Shibayama
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
	//	�o�͕�
	int m_outputWidth;
	//	�o�͍���
	int m_outputHeight;

	//	�L�[�{�[�h
//	std::unique_ptr<DirectX::Keyboard> m_keyboard;
	//	�g���b�J�[
//	std::unique_ptr<DirectX::Keyboard::KeyboardStateTracker> m_tracker;

	//	�X�v���C�g�o�b�`
	std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
	//	�t�H���g
	std::unique_ptr<DirectX::SpriteFont> m_spriteFont;
	//	�G�t�F�N�g�t�@�N�g��
	std::unique_ptr<DirectX::BasicEffect> m_effect;
	//	�R�����X�e�[�g
	std::unique_ptr<DirectX::CommonStates> m_commonStates;

	//	�N���A�[�e�N�X�`��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;


	DirectX::SimpleMath::Matrix m_view;
	DirectX::SimpleMath::Matrix m_proj;

	MapRoom* mapRoom;

};
