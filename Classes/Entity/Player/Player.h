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
* ����״̬������Ŀǰֻ����Ϣ״̬��
*/
class Player : public Entity
{
public:
	virtual bool init();
	void rest();//������������
	void rest_flip();
	void run();//�ܲ���������
	void run_flip();
	void player_animate(const char[]);
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
	std::map<cocos2d::EventKeyboard::KeyCode, bool> getkeyMap();
	float getSpeed();
	void TrueKeyCode(EventKeyboard::KeyCode keycode);	
	void FalseKeyCode(EventKeyboard::KeyCode keycode);
	virtual void update(float delta);
	CREATE_FUNC(Player);

private:
	PlayerTFSM* TFSM;
	PlayerMove* PLAYERMOVE;
	float movespeedX, movespeedY;
	float Speed=NORMAL;
	bool ismoveX;
	bool ismoveY;
	bool isFlip=0;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;
};
