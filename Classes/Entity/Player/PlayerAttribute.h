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
	void HpApMoneySpeedDamageinit();//��ʼ����������
	void Buffinit();
	virtual bool init();
	
	void AddMoney(int income);
	bool CutMoney(int outcome);
	void AddHp(int heal);

	int getHp();
	int getAp();
	int getMoney();
	int getDamage();
	int getShootSpeed();
	//��ȡbuff
	int getHp_Buff();
	int getAp_Buff();
	int getDamage_Buff();
	int getShootSpeed_Buff();
	//����buff
	void setHp_Buff(int buff);
	void setAp_Buff(int buff);
	void setDamage_Buff(int buff);
	void setShootSpeed_Buff(int buff);

	void takeDamage(int damage);//�յ��˺�
	void ApHealingStart(float dt);//��ʼ�ָ�����
	void ApHealing(float dt);//���׻ظ�
	void bindPlayer(Player* player);
	void DeadUpdate(float dt);
	void changeHero(char hero[]);
	virtual void update(float dt);
	void resetColor(float delay);
	void CountTimeUpdate(float dt);

	void Skill_EffectUpdate(float dt);
	Sprite* getSkillEffect();

	CREATE_FUNC(PlayerAttribute);
private:
	static int mhp;
	static int map;
	static int mmoney;
	static int damage;
	static int shootSpeed;

	static int Hp_buff;
	static int Ap_buff;
	static int damage_buff;
	static int shootSpeed_buff;

	int maxHp;
	int maxAp;
	long startTime;
	Player* mplayer;
	bool isDamaged;
	Label* moneyLabel;
	Label* apLabel;
	Label* hpLabel;
	Sprite* SkillEffect;

	static char heroName[10];
};
