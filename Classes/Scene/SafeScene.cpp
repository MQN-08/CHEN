#include"SafeScene.h"
#include"cocos2d.h"
USING_NS_CC;
bool SafeScene::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	
	//����bgm�Լ���tiledmap
	getmusicManager()->changeMusic("bgm/Room.mp3");
	map = TMXTiledMap::create("maps/SafeScene.tmx");
	bindTiledMap(map);
	//���ð�ť
	auto settings = MenuItemImage::create("ui/settings.png", "ui/settings.png", [&](Ref* sender) {
		getmusicManager()->effectPlay("effect/button.mp3");
		getmusicManager()->menu(this);
	});
	//λ��λ�����Ͻ�
	settings->setPosition(visibleSize.width - settings->getContentSize().width / 2, visibleSize.height - settings->getContentSize().height/2);

	//�˵�
	auto menu = Menu::create(settings, nullptr);
	menu->setPosition(Vec2::ZERO);
	addChild(menu);

	//��Ҵ���
	player = Player::create();
	player->setPosition(64 * 4 + 32, 64 * 4 + 32);
	addChild(player);

	/*
	* ���̼������ص�����
	*/
	auto keyBoard = EventListenerKeyboard::create();
	keyBoard->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		switch (keyCode)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_W:
			if (player->getismoveY())
				break;
			else
				player->startmoveY(6.4);
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_A:
			if (player->getismoveX())
				break;
			else
				player->startmoveX(-6.4);
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_S:
			if (player->getismoveY())
				break;
			else
				player->startmoveY(-6.4);
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_D:
			if (player->getismoveX())
				break;
			else
				player->startmoveX(6.4);
			break;
		default:
			break;
		}
	};
	keyBoard->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {
		switch (keyCode)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_W:
			if (player->getismoveY() && player->getspeedY() <= 0)
				break;
			else
				player->stopmoveY();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_A:
			if (player->getismoveX() && player->getspeedX() >= 0)
				break;
			else
				player->stopmoveX();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_S:
			if (player->getismoveY() && player->getspeedY() >= 0)
				break;
			else
				player->stopmoveY();
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_D:
			if (player->getismoveX() && player->getspeedX() <= 0)
				break;
			else
				player->stopmoveX();
			break;
		default:
			break;
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyBoard, this);
	
	this->scheduleUpdate();
	return 1;
}
void SafeScene::update(float dt)
{
	if (player->getismoveX() || player->getismoveY())
	{
		player->playerMove();
	}
}