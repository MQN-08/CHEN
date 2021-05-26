#include"music.h"
#include"ui/CocosGUI.h"
USING_NS_CC;

//��ʼ��
bool MusicManager::init()
{
	if (!manager->isEnabled())
		manager->setEnabled(true);
	return 1;
}

//������Ч
void  MusicManager::effectPlay(char* filename)
{
	effect = manager->play2d(filename, false, effectVolume);
}

//���ı�������
void MusicManager::changeMusic(char* filename)
{
	manager->stop(bgm);
	bgm = manager->play2d(filename, 1, musicVolume);
}

//��һ�β���
void MusicManager::startPlay(char* filename)
{
	manager->stopAll();
	effectVolume = 1.0f;
	musicVolume = 1.0f;
	bgm = manager->play2d(filename, 1, musicVolume);
}
//��������
void MusicManager::changeMusicVolume(float Volume)
{
	manager->setVolume(bgm, Volume);
}

void  MusicManager::changeEffectVolume(float Volume)
{
	manager->setVolume(effect, effectVolume);
}


//���ò˵�
void MusicManager::menu(Scene* p)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	//UI����ͼƬ
	auto UIbackground =Sprite::create("UI/OptionUI.png");
	UIbackground->setPosition(visibleSize / 2);
	p->addChild(UIbackground);

	//������������������
	auto musicLabel = Label::createWithTTF("setMusicVolume", "fonts/Marker Felt.ttf", 24);
	musicLabel->setPosition(UIbackground->getContentSize().width / 2, UIbackground->getContentSize().height - musicLabel->getContentSize().height * 4);
	UIbackground->addChild(musicLabel);

	//��������������
	auto musicSlider = cocos2d::ui::Slider::create();
	musicSlider->loadBarTexture("UI/sliderTrack.png");
	musicSlider->loadSlidBallTextures("UI/sliderThumb.png");
	musicSlider->loadProgressBarTexture("UI/sliderProgress.png");
	musicSlider->setPercent(musicVolume * 100);
	musicSlider->setPosition(Vec2(UIbackground->getContentSize().width / 2, UIbackground->getContentSize().height -
		musicLabel->getContentSize().height * 4 - musicSlider->getContentSize().height * 2));
	musicSlider->addEventListener([&](Ref* sender, cocos2d::ui::Slider::EventType type) {
		switch (type)
		{
		case cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED:
		{
			cocos2d::ui::Slider* slider = dynamic_cast<cocos2d::ui::Slider*>(sender);
			int percent = slider->getPercent();
			int maxPercent = slider->getMaxPercent();
			musicVolume = 1.0f*percent / maxPercent;
			AudioEngine::setVolume(bgm, musicVolume);
			break;
		}
		default:
			break;
		}
	});
	UIbackground->addChild(musicSlider);

	//��Ч��������������
	auto effectLabel = Label::createWithTTF("setEffectVolume", "fonts/Marker Felt.ttf", 24);
	effectLabel->setPosition(UIbackground->getContentSize().width / 2, UIbackground->getContentSize().height - 
							musicLabel->getContentSize().height * 4 - effectLabel->getContentSize().height * 4);
	UIbackground->addChild(effectLabel);

	//��Ч����������
	auto effectSlider = cocos2d::ui::Slider::create();
	effectSlider->loadBarTexture("UI/sliderTrack.png");
	effectSlider->loadSlidBallTextures("UI/sliderThumb.png");
	effectSlider->loadProgressBarTexture("UI/sliderProgress.png");
	effectSlider->setPercent(effectVolume * 100);
	effectSlider->setPosition(Vec2(UIbackground->getContentSize().width / 2, UIbackground->getContentSize().height -
		musicLabel->getContentSize().height * 4 - effectLabel->getContentSize().height * 4 - effectSlider->getContentSize().height*2));
	effectSlider->addEventListener([&](Ref* sender, cocos2d::ui::Slider::EventType type) {
		switch (type)
		{
		case cocos2d::ui::Slider::EventType::ON_PERCENTAGE_CHANGED:
		{
			cocos2d::ui::Slider* slider = dynamic_cast<cocos2d::ui::Slider*>(sender);
			int percent = slider->getPercent();
			int maxPercent = slider->getMaxPercent();
			effectVolume = 1.0f * percent / maxPercent;
			AudioEngine::setVolume(effect, effectVolume);
			break;
		}
		default:
			break;
		}
	});
	UIbackground->addChild(effectSlider);

	//�˳���Ϸ

	auto closeGameLable = Label::createWithTTF("Exit Game", "fonts/Marker Felt.ttf", 48);
	auto closeGameItem = MenuItemLabel::create(closeGameLable, [=](Ref* sender) {
		effectPlay("effect/button.mp3");
		Director::getInstance()->end();
	});
	closeGameItem->setPosition(UIbackground->getContentSize().width / 2, closeGameItem->getContentSize().height * 2);

	//�˳�����
	auto closeLabel = Label::createWithTTF("Return", "fonts/Marker Felt.ttf", 48);
	auto closeItem = MenuItemLabel::create(closeLabel, [=](Ref* sender) {
		effectPlay("effect/button.mp3");
		p->removeChild(UIbackground);
	});
	closeItem->setPosition(UIbackground->getContentSize().width / 2, closeItem->getContentSize().height * 2 + closeGameItem->getContentSize().height * 2);

	auto optionUI = Menu::create(closeGameItem,closeItem, nullptr);
	optionUI->setPosition(Vec2::ZERO);
	UIbackground->addChild(optionUI);
}
int MusicManager::bgm;
float MusicManager::musicVolume;
int MusicManager::effect;
float MusicManager::effectVolume;