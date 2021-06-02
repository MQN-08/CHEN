#include"Player.h"
#include"PlayerStates.h"
#include"Player/PlayerAttribute.h"
#include"PlayerTFSM/PlayerTFSM.h"
#include"Player/PlayerMove.h"
#include"Weapon/Pistol.h"
#include"Weapon/Sword.h"
#include"music.h"
bool Player::init()
{
	if (weapon1!=nullptr)
	{
		weapon1->bindPlayer(this);
		this->addChild(weapon1, 2);
	}
	bindSprite(Sprite::create("Player/knight_rest1.png"));
	playerAttribute = PlayerAttribute::create();
	playerAttribute->retain();
	playerAttribute->bindPlayer(this);
	TFSM = PlayerTFSM::create();
	TFSM->retain();
	TFSM->bindPlayer(this);
	this->scheduleUpdate();//��������update����������
	this->schedule(CC_SCHEDULE_SELECTOR(Player::TFSMupdate), 0.4f);//ÿ0.4f����һ��״̬�����º���
	this->schedule(CC_SCHEDULE_SELECTOR(Player::FlipUpdate), 0.01f);
	PLAYERMOVE = PlayerMove::create();
	PLAYERMOVE->retain();
	PLAYERMOVE->bindPlayer(this);
	
	AnimateFrameCache_init();
	return 1;
}

PlayerAttribute* Player::getPlayerAttribute()
{
	return playerAttribute;
}

PlayerMove* Player::getplayermove()
{
	return PLAYERMOVE;
}
void Player::AnimateFrameCache_init()
{
	m_frameCache = SpriteFrameCache::getInstance();//��ȡ��������ʵ������
	m_frameCache->addSpriteFramesWithFile("Player/knight_animate.plist", "Player/knight_animate.png");//���֡�����ļ�������
}
void Player::rest()
{

	
	Vector<SpriteFrame*>frameArray;//�������б���
	for (int i = 1; i <= 4; i++)
	{
		char s[40];
		sprintf(s, "knight_rest%d.png", i);
		auto frame = m_frameCache->getSpriteFrameByName(s);
		frameArray.pushBack(frame);//��֡���뵽������
	}
	Animation* animation = Animation::createWithSpriteFrames(frameArray);//��������
	//animation->setLoops(-1);//-1��ʾ���޲���
	animation->setDelayPerUnit(0.1f);//ÿ����ͼƬ�ļ��ʱ��
	auto* action = Animate::create(animation);
	getSprite()->runAction(action);

	AnimationCache::destroyInstance();//����������


}

void Player::run()
{
	
	Vector<SpriteFrame*>frameArray;
	for (int i = 2; i <= 4; i++)
	{
		char s[40];
		sprintf(s, "knight_move%d.png", i);
		auto frame = m_frameCache->getSpriteFrameByName(s);
		frameArray.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(frameArray);
	animation->setDelayPerUnit(0.1f);
	auto* action = Animate::create(animation);
	getSprite()->runAction(action);
	AnimationCache::destroyInstance();
	
}

void Player::dead()
{
	Vector<SpriteFrame*>frameArray;
	auto frameCache= SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("Player/knight_animate.plist", "Player/knight_animate.png");
	auto frame1 =frameCache->getSpriteFrameByName("knight_down.png");
	frameArray.pushBack(frame1);


	Animation* animation = Animation::createWithSpriteFrames(frameArray);
	animation->setDelayPerUnit(0.1f);
	auto* action = Animate::create(animation);
	this->getSprite()->runAction(action);

	AnimationCache::destroyInstance();
}

/*

* Ŀǰbug��
* Ŀǰ����
*/


void Player::TFSMupdate(float dt)
{
	TFSM->update(dt);
}

void Player::trueMouseMap(EventMouse::MouseButton key)
{
	mouseMap[key] = 1;
}

void Player::flaseMouseMap(EventMouse::MouseButton key)
{
	mouseMap[key] = 0;
}

void Player::update(float delta)//update for Player
{
	//Player�˶�

	PLAYERMOVE->Move();
	if(weapon1)
		weapon1->update(delta);
	if (weapon2)
		weapon2->update(delta);
	float x = mouseLocation.x;
	float y = mouseLocation.y;
//	pistol->getSprite()->setRotation(x);

	//CCLOG("%f,%f", x, y);
}
bool Player::getIsFlip()
{
	return PLAYERMOVE->getIsFlip();
}

std::map<EventMouse::MouseButton, bool> Player::getMouseMap()
{
	return mouseMap;
}
Weapon* Player::getWeapon1()
{
	return weapon1;
}
Weapon* Player::getWeapon2()
{
	return weapon2;
}
void Player::PistolInit()
{
	weapon1 = Pistol::create();
	weapon1->retain();
	weapon1->bindPlayer(this);
	weapon1->setPosition(getSprite()->getContentSize().width/2 , getContentSize().height / 2);
	weapon1->setTag(Weapon::MyWeapon::Pistol_Player);
	
}
void Player::SwordInit()
{
	weapon1 = Sword::create();
	weapon1->retain();
	weapon1->bindPlayer(this);
	weapon1->setPosition(getSprite()->getContentSize().width / 2+5,-20);

	weapon1->setTag(Weapon::MyWeapon::Sword_Player);
}
void Player::changeMouseLocation(Vec2 location)
{
	mouseLocation = location;
}

Vec2 Player::getMouseLocation()
{
	
	return mouseLocation;
}
void Player::deadNotice()
{
	
}
void Player::FlipUpdate(float dt)//��ת
{
	if (getIsFlip() == 0)
		this->getSprite()->setFlippedX(0);
	else
		this->getSprite()->setFlippedX(1);
}
Weapon* Player::weapon1;
Weapon* Player::weapon2;