#pragma once
#include"Monster.h"
#include"MonsterPistolAmmo.h"
/*Զ�̹���
* ���ݶ�������־��廯
*/
class RemoteMonster :public Monster
{
public:
	virtual void MonsterAnimate(char type[]);
	virtual void dead();
	virtual void FramCacheInit(char Name[]);
	void InitWithName(char s[]);
	MonsterPistolAmmo* MonsterAttack();
	CREATE_FUNC(RemoteMonster);
private:
	char MonsterName[30];
	SpriteFrameCache* m_frameCache;
};