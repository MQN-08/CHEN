#pragma once
#include"cocos2d.h"
#include"Entity/Entity.h"
/*
* ������Թ�����
* ����
* UI
* HP,���ף���Ǯ�ĳ�ʼ���Լ��䶯
*/
class Player;
USING_NS_CC;
class PlayerAttribute :public Entity
{
public:
	void hpApMoneyinit(int hp, int ap);//��ʼ����������
	virtual bool init();
	int getHp();
	int getAp();
	int getMoney();
	void takeDamage(int damage);//�յ��˺�
	void ApHealingStart(float dt);//��ʼ�ָ�����
	void ApHealing(float dt);//���׻ظ�
	void bindPlayer(Player* player);
	virtual void update(float dt);
	CREATE_FUNC(PlayerAttribute);
private:
	static int mhp;
	static int map;
	static int mmoney;
	Player* mplayer;
	bool isDamaged;
	Label* moneyLabel;
	Label* apLabel;
	Label* hpLabel;
	
};
