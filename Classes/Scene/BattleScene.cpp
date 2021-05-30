#include"BattleScene.h"
#include"cocos2d.h"
#include"json.h"
#include <stdlib.h>
#include <time.h> 
#include"Player/PlayerMove.h"
#include"Player/PlayerAttribute.h"
#include"Monster/Monster.h"
#include"Monster/CloseMonster/CloseMonster_1.h"
#include"Monster/CloseMonster/CloseMonster_2.h"
#include"Monster/CloseMonster/CloseMonster_3.h"
#include"Monster/CloseMonster/CloseMonster_4.h"
USING_NS_CC;
bool BattleScene::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();


	//����ͼƬ����
	auto backgroundSprite = Sprite::create("background/BattleScene.png");
	backgroundSprite->setPosition(origin.x + backgroundSprite->getContentSize().width / 2, origin.y + backgroundSprite->getContentSize().height / 2);
	this->addChild(backgroundSprite, -1);



	//����bgm�Լ���tiledmap
	getmusicManager()->changeMusic("bgm/Room.mp3");
	srand((unsigned)time(NULL));
	int i = rand()%3;
	char s[40];	
	i = 0;
	sprintf(s, "maps/BattleScene%d.tmx", i);
	map = TMXTiledMap::create(s);
	bindTiledMap(map);

	//���ð�ť
	auto settings = MenuItemImage::create("ui/settings.png", "ui/settings.png", [&](Ref* sender) {
		getmusicManager()->effectPlay("effect/button.mp3");
		getmusicManager()->menu(this);
		});
	//λ��λ�����Ͻ�
	settings->setPosition(visibleSize.width - settings->getContentSize().width / 2, visibleSize.height - settings->getContentSize().height / 2);

	//�˵�
	auto menu = Menu::create(settings, nullptr);
	menu->setPosition(Vec2::ZERO);
	addChild(menu, 5);

	//��Ҵ���
	bindPlayer(Player::create());
	getPlayer()->setPosition(64 * 4 + 32, 64 * 4 + 32);
	getPlayer()->getplayermove()->bindMap(map);//PlayerMove�������ͼ��
	getPlayer()->getPlayerAttribute()->setPosition(getPlayer()->getPlayerAttribute()->getSprite()->getContentSize().width / 2,
		visibleSize.height - getPlayer()->getPlayerAttribute()->getSprite()->getContentSize().height / 2);//����UIλ������
	this->addChild(getPlayer()->getPlayerAttribute(), 5);
	this->addChild(getPlayer(), 2);


	//��ս���ﴴ��
	 Monster_1 =  CloseMonster_1::create();
	 Monster_1->bindScene(this);
	 Monster_1->Birth("Monster_birth1");
	this->addChild( Monster_1, 4);

	CloseMonster_2* Monster_2 = CloseMonster_2::create();
	Monster_2->bindScene(this);
	Monster_2->Birth("Monster_birth2");
	this->addChild(Monster_2, 4);

	CloseMonster_3* Monster_3 = CloseMonster_3::create();
	Monster_3->bindScene(this);
	Monster_3->Birth("Monster_birth3");
	this->addChild(Monster_3, 4);

	CloseMonster_4* Monster_4 = CloseMonster_4::create();
	Monster_4->bindScene(this);
	Monster_4->Birth("Monster_birth4");
	this->addChild(Monster_4, 4);

	//�����Ŵ���
	safeGate = Gate::create();
	safeGate->setPosition(64 * 9.45, 64 * 10);
	safeGate->bindPlayer(getPlayer());
	safeGate->bindStart(this);
	safeGate->bindDestination(this);
	//this->addChild(safeGate, 5);

	////eventlistener,���̼����������ƶ�����
	auto myKeyListener = EventListenerKeyboard::create();
	myKeyListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, cocos2d::Event* event)//���̰���ʱ��Ӧ
	{
		getPlayer()->getplayermove()->TrueKeyCode(keycode);//PlayerMove��keyMap�Ķ�Ӧ������true

	};

	myKeyListener->onKeyReleased = [=](EventKeyboard::KeyCode keycode, cocos2d::Event* event)//�����ɿ�ʱ��Ӧ
	{
		getPlayer()->getplayermove()->FalseKeyCode(keycode);
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(myKeyListener, this);
	this->scheduleUpdate();

	this->schedule(CC_SCHEDULE_SELECTOR(BattleScene::test), 1.0f);

	return 1;
}
void BattleScene::update(float dt)
{
	//����Player��update��Player��update�ٵ���PlayMove��move��������ֹ���ޣ�


	getPlayer()->update(dt);
	//safeGate->update(dt);
}
void BattleScene::test(float dt)
{
	Monster_1->takingDamage(1);
}