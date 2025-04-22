#include <DxLib.h>			// DxLib���g�p���邽�߂ɕK�{


// �Q�[���v���O������ WinMain ����n�܂�܂�
int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);			// �E�B���h�E���[�h�ɂ��邩�ǂ���
	SetGraphMode(640, 480, 32);		// �E�B���h�E�̉𑜓x��ݒ肷��

#ifndef _DEBUG
	// �����[�X�ł̓��O���o���Ȃ�
	SetOutApplicationLogValidFlag( false );
#endif

	// �c�w���C�u���������������@��{�I�ɂ͂�������DxLib�֐����g��
	if (DxLib_Init() == -1) return -1;

	// ��ԍŏ��ɂP�񂾂���鏈��
	SetDrawScreen(DX_SCREEN_BACK);	// ��ʂ̂�����𖳂���
	SetTransColor(255, 0, 255);		// ���ߐF�w��@����͐^���F�𓧖�

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)	// ��肪����������I��
	{
		// �uesc�L�[�v�������ꂽ��I��
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;

		// ��ʂ���x�����Ȃ���Ԃ�
		ClearDrawScreen();

		// �Q�[���{�̖̂��߂͂����艺�ɏ���
		
		// �Q�[���{�̖̂��߂͂������ɏ���

		// �쐬������ʂ����j�^�[�֓]��
		ScreenFlip();

	}

	// �I���O����==================
	DxLib_End();			// �c�w���C�u�����g�p�̏I������
	//=============================

	return 0;				// �v���O�����̏I�� 
}
