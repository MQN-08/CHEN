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
	bool moveToDestination(Vec2 destination);
//	void move();//����ʵ���ƶ�
	void StrollAround();//����С��Χ�����ƶ�
	void ApproachPlayer(Vec2 playerDestination);//��������ҷ��򿿽�
	bool isAround();//�ж�����Ƿ��ڸ���
	void bindScene(NormalBattleScene* scene);
	void takingDamage(int damage);//�����ܵ��˺�
	bool CanReachto(int Mapx,int Mapy,bool isDip);//�ж������ǲ���ǽ��
	void Birth(int i);
	void reSetColor(float delay);
	
	virtual void MonsterAnimate(char type[]);
	virtual MonsterPistolAmmo* MonsterAttack();
	virtual void InitWithName(char s[]);
	virtual void dead();
	virtual void FramCacheInit(char Name[]);

	void FlipUpdate(float dt);
	void TFSMupdate(float dt);
	void DeadUpdate(float dt);//�������
	void setPhysicsBody(PhysicsBody* body);
	bool CanSee();

	bool getIsDead();
	PhysicsBody* getMyBody();
	friend class BattleScene;

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
	float Width;
	float Height;
	PhysicsBody* PhysicsBody_M;
};