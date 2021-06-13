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

	void changeHp(int n);
	void changeAp(int n);
	void changeMoney(int n);
	void changeDamage(int n);
	void changeShootSpeed(int n);


	//��ȡbuff
	int getHp_Buff();
	int getAp_Buff();
	int getDamage_Buff();
	int getShootSpeed_Buff();
	//�ı�buff
	void changeHp_Buff(int buff);
	void changeAp_Buff(int buff);
	void changeDamage_Buff(int buff);
	void changeShootSpeed_Buff(int buff);

	void takeDamage(int damage);//�յ��˺�
	void ApHealingStart(float dt);//��ʼ�ָ�����
	void ApHealing(float dt);//���׻ظ�
	void bindPlayer(Player* player);
	void DeadUpdate(float dt);
	void changeHero(char hero[]);
	virtual void update(float dt);
	void resetColor(float delay);
	void CountTimeUpdate(float dt);


	void changeAttribute();
	void Skill_EffectUpdate(float dt);
	void Buff_EffectUpdate(float dt);
	Sprite* getSkillEffect();
	Sprite* getBuffEffect();
	CREATE_FUNC(PlayerAttribute);
private:
	static int mhp;
	static int map;
	static int mmoney;
	static int damage;
	static int shootSpeed;

	int Hp_buff;
	int Ap_buff;
	int damage_buff;
	int shootSpeed_buff;

	int maxHp;
	int maxAp;
	long startTime;
	Player* mplayer;
	bool isDamaged;
	Label* moneyLabel;
	Label* apLabel;
	Label* hpLabel;
	Sprite* SkillEffect;
	Sprite* BuffEffect;
	static char heroName[10];
};
