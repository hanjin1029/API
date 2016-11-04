#pragma once

class CDevice
{
// ���� ���� �ҽ� Ȯ�� �� �м� �ؾ��� ��

// 1. stdafx.h�� ������� �߰� �κ�
// 2. maingame Ŭ���� Initialize �� Release �Լ�
// 3. Stage Ŭ���� Initialize �� Progress �Լ� 
// 4. ������Ʈ ����(�Ϻ� ������ Texture ����ó�� Sound������ �ִ� �� Ȯ��)
// 5. ���Ҿ wav���ϸ� �����Ǵ� ������. 
// 6. Ȥ�� ������ �۾��ϴٰ� �ȵȴٸ� directx sdk�� ������, �� ��ġ �� ���ͳݿ��� 
//	  �ٿ�޾� �ʼ������� ��ġ�ؾ� ��. june2010������ �ְ�, ��ġ �� ���ٴ� ���� �ƴ�.
//	  �ڼ��� ��ġ������ ���ͳݿ� �˻��ϸ� ���� ����. ������ �𸣰����� �����ð��� ������.
//	  ��ȭ�� ���ڷ� �ϱ⿣ �ʹ� �� ������.


private:
//directx sdk (����ũ�μ���Ʈ���� ��ǻ�Ϳ��ִ� �ϵ��� ���� ����Ҽ� �ְ�
	// �������� �Լ���, ���������� �����س��� ������ϰ� ���̺귯�������� ����.)
	//���̷�Ʈ ���� �������̽�
	LPDIRECTSOUND				m_pSound; //����ī�带 ��ǥ�ϴ� ��ü.
	vector<LPDIRECTSOUNDBUFFER> m_vecSoundBuff;	//���������� �ε��ؼ� ������ ����

public:
	HRESULT Init(void);	// ��ġ�� �ʱ�ȭ �ϴ¿�Ȱ.
	HRESULT LoadWave(TCHAR* pFileName);	//���ϰ�θ� ���� ������ �о� �帮�ڴ�.
	void SoundPlay(int iIndex /*���° ������ ����ҷ�?*/, DWORD dwFlag/*���ѷ���, �ѹ�*/); //������ ��� �ϰڴ�.
	void SoundStop(int iIndex);
	bool SoundPlaying(int iIndex);	// ���� iIndex��° ���尡 ����ǰ��ִ��� �ƴ���.

private:
	static CDevice* m_pInstance;

public:
	static inline CDevice* GetInstance(void)
	{
		if(!m_pInstance)
			m_pInstance = new CDevice;

		return m_pInstance;
	}
public:
	inline void DestroyInst(void)
	{
		if(m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = NULL;
		}
	}



public:
	CDevice(void);
	~CDevice(void);
};
