#pragma once
#include"Entity/Entity.h"
#include"cocos2d.h"
#define NORMAL 35
class NormalScene;
class MonsterTFSM;
class BattleScene;
class NormalBattleScene;
class MonsterPistolAmmo;
USING_NS_CC;
//�������
class  Monster : public Entity
{
public:

	void MoveUpdate(float dt);

	void move();//����ʵ���ƶ�
	void StrollAround();//����С��Χ�����ƶ�
	void ApproachPlayer();//��������ҷ��򿿽�
	bool isAround();//�ж�����Ƿ��ڸ���
	void bindScene(NormalBattleScene* scene);
	void takingDamage(int damage);//�����ܵ��˺�
	bool isWall(float x,float y);//�ж������ǲ���ǽ��
	void Birth(const std::string place_name);

	
	virtual void rest();

	virtual void run();

	virtual void dead();

	void FlipUpdate(float dt);
	void TFSMupdate(float dt);
	void DeadUpdate(float dt);//�������
	bool getIsDead();
	friend class BattleScene;
	virtual MonsterPistolAmmo* MonsterAttack();
	CREATE_FUNC( Monster);

protected:
	int mHp;
	NormalBattleScene* mScene;
	MonsterTFSM* TFSM_M;
	float movespeedX;
	float movespeedY;
	float Speed=NORMAL;
	bool isFlip=0;
	bool isdead = 0;
	SpriteFrameCache* m_frameCache;

};