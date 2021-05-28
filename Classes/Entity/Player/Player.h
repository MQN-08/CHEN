#pragma once
#include"Entity.h"
#include"PlayerTFSM.h"
#include"PlayerMove.h"
#define NORMAL 2
USING_NS_CC;
/*
* �����
* ����
* ��ʼ��
* �ƶ�
* ����״̬����
*/
class Player : public Entity
{
public:
	virtual bool init();
	void rest();//������������
	void rest_flip();
	void run();//�ܲ���������
	void run_flip();
	void TFSMupdate(float dt);//����״̬��ר��update��ÿ0.4fһ�ε���
	PlayerMove* getplayermove();




	virtual void update(float delta);

	CREATE_FUNC(Player);
	friend class PlayerMove;
private:
	PlayerTFSM* TFSM;
	PlayerMove* PLAYERMOVE;
	int Health;//Ѫ��
	int Armor;//����
	int Mana;//����



};
