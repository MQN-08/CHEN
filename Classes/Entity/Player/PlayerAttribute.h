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
	void hpApMoneyinit();//��ʼ����������
	virtual bool init();
	
	void AddMoney(int income);
	bool CutMoney(int outcome);
	void AddHp(int heal);

	int getHp();
	int getAp();
	int getMoney();
	void takeDamage(int damage);//�յ��˺�
	void ApHealingStart(float dt);//��ʼ�ָ�����
	void ApHealing(float dt);//���׻ظ�
	void bindPlayer(Player* player);
	void DeadUpdate(float dt);
	void changeHero(char hero[]);
	virtual void update(float dt);
	void resetColor(float delay);
	void CountTimeUpdate(float dt);
	CREATE_FUNC(PlayerAttribute);
private:
	static int mhp;
	static int map;
	static int mmoney;
	int maxHp;
	int maxAp;
	long startTime;
	Player* mplayer;
	bool isDamaged;
	Label* moneyLabel;
	Label* apLabel;
	Label* hpLabel;
	static char heroName[10];
};
