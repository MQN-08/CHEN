#include"SafeScene.h"
#include"cocos2d.h"
#include"json.h"
#include"Gate.h"
USING_NS_CC;
bool SafeScene::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();


	//背景图片精灵
	auto backgroundSprite = Sprite::create("background/SafeScene.png");
	backgroundSprite->setPosition(origin.x + backgroundSprite->getContentSize().width / 2, origin.y + backgroundSprite->getContentSize().height / 2);
	this->addChild(backgroundSprite,1);



	//更改bgm以及绑定tiledmap
	getmusicManager()->changeMusic("bgm/Room.mp3");
	map = TMXTiledMap::create("maps/SafeScene.tmx");
	bindTiledMap(map);

	//设置按钮
	auto settings = MenuItemImage::create("ui/settings.png", "ui/settings.png", [&](Ref* sender) {
		getmusicManager()->effectPlay("effect/button.mp3");
@@ -21,36 +32,51 @@ bool SafeScene::init()
	//菜单
	auto menu = Menu::create(settings, nullptr);
	menu->setPosition(Vec2::ZERO);
	addChild(menu);
	addChild(menu,5);

	//玩家创建
	player = Player::create();
	player->setPosition(64 * 4 + 32, 64 * 4 + 32);
	addChild(player);
	player->getplayermove()->bindMap(map);//PlayerMove跟这个地图绑定
	this->addChild(player,2);

	//传送门创建
	safeGate = Gate::create();
	safeGate->setPosition(64*9.45,64*10);
	safeGate->bindPlayer(player);
	safeGate->bindStart(this);
	safeGate->bindDestination(this);
	this->addChild(safeGate, 5);

	////eventlistener,键盘监听，用于移动人物
	auto myKeyListener = EventListenerKeyboard::create();
	myKeyListener->onKeyPressed = [=](EventKeyboard::KeyCode keycode, cocos2d::Event* event)//键盘按下时响应
	{
		//CCLOG("keycode%d", keycode);
		player->TrueKeyCode(keycode);
		player->getplayermove()->TrueKeyCode(keycode);//PlayerMove里keyMap的对应键码置true

	};

	myKeyListener->onKeyReleased = [=](EventKeyboard::KeyCode keycode, cocos2d::Event* event)//键盘松开时响应
	{

		//CCLOG("keyboard is released,code is %d", keycode);
		player->FalseKeyCode(keycode);
		player->getplayermove()->FalseKeyCode(keycode);
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(myKeyListener, this);
	this->scheduleUpdate();


	return 1;
}

void SafeScene::update(float dt)
{
	//调用Player的update，里面有运动的实现
	//调用Player的update，Player的update再调用PlayMove的move函数（禁止套娃）
	//isWall(player->getPositionX(), player->getPositionY())
	//json使用示例
	player->update(dt);
} 
	safeGate->update(dt);
}
