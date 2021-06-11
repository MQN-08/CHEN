#include"Monster.h"
#include"NormalScene.h"
#include"MonsterStates.h"
#include"MonsterTFSM.h"
#include"CloseMonster.h"
#include"Player.h"
#include <stdlib.h>
#include <time.h> 
#include"MonsterDashAmmo.h"
#include"MonsterShockAmmo.h"
#include"json.h"

bool CloseMonster::init()
{
	this->schedule(CC_SCHEDULE_SELECTOR(CloseMonster::update), 50.0f);
	this->schedule(CC_SCHEDULE_SELECTOR(CloseMonster::DashUpdate), 0.01f);
	this->schedule(CC_SCHEDULE_SELECTOR(CloseMonster::ShockUpdate), 0.01f);
	return 1;
}

Ammo* CloseMonster::MonsterAttack()
{
	return MonsterDashAmmo::create();
}
void CloseMonster::DashAttack()
{
	if (!DashAmmo)//���û�ڳ�ײ
	{
		DashAmmo = MonsterDashAmmo::create();
		this->addChild(DashAmmo);
		//��Ӹ���
		auto physicsBody_M = PhysicsBody::createBox(Size(46.0f, 48.0f),
			PhysicsMaterial(0.0f, 0.0f, 0.0f));

		DashAmmo->addComponent(physicsBody_M);

		physicsBody_M->setDynamic(false);
		physicsBody_M->setCategoryBitmask(0x0010);
		physicsBody_M->setCollisionBitmask(0x0010);
		physicsBody_M->setContactTestBitmask(0x0010);
		DashAmmo->setPhysicsBody(physicsBody_M);
		DashAmmo->setTag(AllTag::MonsterAmmo_CloseTAG);

	}	
}
void CloseMonster::ShockAttack()
{
	if (!ShockAmmo)
	{
		ShockAmmo = MonsterShockAmmo::create();
		this->addChild(ShockAmmo,-1);

		auto physicsBody_M = PhysicsBody::createBox(Size(57.0f, 62.0f),
			PhysicsMaterial(0.0f, 0.0f, 0.0f));
		ShockAmmo->setPosition(this->getSprite()->getContentSize()/2);
		ShockAmmo->getSprite()->setScale(2);
		ShockAmmo->addComponent(physicsBody_M);
		physicsBody_M->setDynamic(false);
		physicsBody_M->setCategoryBitmask(0x0010);
		physicsBody_M->setCollisionBitmask(0x0010);
		physicsBody_M->setContactTestBitmask(0x0010);
		ShockAmmo->setPhysicsBody(physicsBody_M);
		ShockAmmo->setTag(AllTag::MonsterAmmo_CloseTAG);

	}
}
void CloseMonster::stopAttack()
{
	if (DashAmmo)
	{
		this->removeChild(DashAmmo);
		DashAmmo = NULL;
	}
	if (ShockAmmo)
	{
		this->removeChild(ShockAmmo);
		ShockAmmo = NULL;
	}


}
bool CloseMonster::isAttack()
{
	return (DashAmmo||ShockAmmo) ? true : false;
}
void CloseMonster::update(float dt)
{
	if (isAround()&&CanSee())//���￴�����������Χ
	{
		if (this->getTag()==AllTag::pig_monster_TAG)//��ͻ�ͽ�
			DashAttack();
		else if(this->getTag() == AllTag::snow_monster_TAG)//ѩ�ֺ���
			ShockAttack();
	}
	else
		stopAttack();

}
void CloseMonster::DashUpdate(float dt)
{
	if (mHp <= 0)//������ֹͣ����
		stopAttack();
	if (DashAmmo)
	{
		if (isFlip)//���������ķ�ת��λ�õ���
		{
			DashAmmo->getSprite()->setFlippedX(1);
			DashAmmo->setPosition(Vec2(0, this->getSprite()->getContentSize().height / 2));
		}

		else
		{
			DashAmmo->getSprite()->setFlippedX(0);

			DashAmmo->setPosition(Vec2(this->getSprite()->getContentSize().width, this->getSprite()->getContentSize().height / 2));
		}

	}

}
void CloseMonster::ShockUpdate(float dt)
{
	if (mHp <= 0)
		stopAttack();

}
