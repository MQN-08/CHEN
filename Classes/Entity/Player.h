#pragma once
#include"Entity.h"
#include"PlayerTFSM/PlayerTFSM.h"
USING_NS_CC;
/*
* �����
* ����
* ��ʼ��
* �ƶ�
* ����״̬������Ŀǰֻ����Ϣ״̬��
*/
class Player : public Entity
{
public:
	virtual bool init();
	virtual void update(float delta);
	void rest();//������������
	void TFSMupdate(float dt);//����״̬��ר��update��ÿ0.4fһ�ε���
	void playerMove();//�ƶ�����
	void startmoveX(float x);
	void startmoveY(float y);
	void stopmoveX();
	void stopmoveY();
	bool getismoveX();
	bool getismoveY();
	float getspeedX();
	float getspeedY();
	CREATE_FUNC(Player);

private:
	PlayerTFSM* TFSM;
	float movespeedX, movespeedY;
	bool ismoveX;
	bool ismoveY;
};
