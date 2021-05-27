#pragma once
#include"Entity.h"
#include"PlayerTFSM/PlayerTFSM.h"
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
	void TrueKeyCode(EventKeyboard::KeyCode keycode);	
	void FalseKeyCode(EventKeyboard::KeyCode keycode);
	virtual void update(float delta);
	CREATE_FUNC(Player);

private:
	PlayerTFSM* TFSM;
	float movespeedX, movespeedY;
	float Speed=NORMAL;
	bool ismoveX;
	bool ismoveY;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;
};
