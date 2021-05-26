#include"Player.h"
bool Player::init()
{
	ismoveX = 0;
	ismoveY = 0;
	bindSprite(Sprite::create("Player/knight_rest1.png"));
	TFSM = PlayerTFSM::create();
	TFSM->retain();
	TFSM->bindPlayer(this);
	this->scheduleUpdate();//��������update����������
	this->schedule(CC_SCHEDULE_SELECTOR(Player::TFSMupdate), 0.4f);//ÿ0.4f����һ��״̬�����º���
	return 1;
}

void Player::rest()
{
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(4);
	animFrames.pushBack(SpriteFrame::create("Player/knight_rest1.png", Rect(0, 0, 52, 60)));
	animFrames.pushBack(SpriteFrame::create("Player/knight_rest2.png", Rect(0, 0, 52, 60)));
	animFrames.pushBack(SpriteFrame::create("Player/knight_rest3.png", Rect(0, 0, 52, 60)));
	animFrames.pushBack(SpriteFrame::create("Player/knight_rest4.png", Rect(0, 0, 52, 60)));
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);
	getSprite()->runAction(RepeatForever::create(animate));
}

/*
* ����ƶ�ԭ��
* WS��ӦmoveY,�ֱ����ж��Ƿ����ƶ��Լ��ƶ��ٶ�����������ADͬ���ӦmoveX��
* ���°���ʱ�������ʱ��һ����δ���£���ismove��1��������ʼ�ƶ��������趨��Ӧ���ƶ��ٶ�
* �ɿ�ʱ����ismove���ƶ��ٶ���0
* Ŀǰbug���ڰ���Wʱ����S����������������(����û����)�������ڳ�����סS��������ɿ�W�������վ��ԭ�ض����������ߡ�AD�����ͬ��
* Ŀǰ���󣺱߽��ж��Լ���ͷ�ƶ����Լ�����״̬�����л���
*/
void Player::playerMove()
{
	auto move = MoveBy::create(0, Vec2(movespeedX, movespeedY));
	this->runAction(move);
}

void Player::TFSMupdate(float dt)
{
	TFSM->update(dt);
}

void Player::startmoveX(float x)
{
	movespeedX = x;
	ismoveX = 1;
}

void Player::startmoveY(float y)
{
	movespeedY = y;
	ismoveY = 1;
}

void Player::stopmoveX()
{
	movespeedX = 0;
	ismoveX = 0;
}

void Player::stopmoveY()
{
	movespeedY = 0;
	ismoveY = 0;
}

bool Player::getismoveX()
{
	return ismoveX;
}

bool Player::getismoveY()
{
	return ismoveY;
}

float Player::getspeedX()
{
	return movespeedX;
}

float Player::getspeedY()
{
	return movespeedY;
}

std::map<cocos2d::EventKeyboard::KeyCode, bool> Player::getkeyMap()//��ȡkeyMap
{
	return keyMap;
}

void Player::TrueKeyCode(EventKeyboard::KeyCode keycode)//���̰��£���Ӧkeycode��true
{
	keyMap[keycode] = true;
}
void Player::FalseKeyCode(EventKeyboard::KeyCode keycode)//�����ɿ�����Ӧkeycode��false
{
	keyMap[keycode] = false;
}

void Player::update(float delta)//update for Player
{
	auto right = (EventKeyboard::KeyCode)127;
	auto left = (EventKeyboard::KeyCode)124;
	auto up = (EventKeyboard::KeyCode)146;
	auto down = (EventKeyboard::KeyCode)142;

	if (keyMap[up])
	{
		startmoveY(Speed);
	}
	if (keyMap[down])
	{
		startmoveY(-Speed);
	}
	if (keyMap[left])
	{
		startmoveX(-Speed);
	}
	if (keyMap[right])
	{
		startmoveX(Speed);
	}
	if (keyMap[right] && keyMap[up])
	{
		startmoveX(Speed);
		startmoveY(Speed);
	}
	if (keyMap[left] && keyMap[up])
	{
		startmoveX(-Speed);
		startmoveY(Speed);
	}
	if (keyMap[left] && keyMap[down])
	{
		startmoveX(-Speed);
		startmoveY(-Speed);
	}
	if (keyMap[right] && keyMap[down])
	{
		startmoveX(Speed);
		startmoveY(-Speed);
	}
	playerMove();
	stopmoveX();
	stopmoveY();

}