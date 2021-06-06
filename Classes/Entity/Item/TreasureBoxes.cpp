#include"TreasureBoxes.h"
#include"AllTag.h"

#include"BattleMap.h"
USING_NS_CC;
bool TreasureBoxes::init()
{
	bindSprite(Sprite::create("Items/box_1.png"));
	this->schedule(CC_SCHEDULE_SELECTOR(TreasureBoxes::update), 0.01f);
	return 1;
}
void TreasureBoxes::Interact(char s[])
{
	if (isAround())
	{
		if (!isOpen)//�ǹص�
		{
			bindSprite(Sprite::create("Items/box_2.png"));
			isOpen = 1;
			if (isUsed == 0)//û�ù�
			{
				notice(s);
				isUsed = 1;
				startTime = clock();
			}

		}
		else//�ǿ��� 
		{

			this->removeAllChildren();
			bindSprite(Sprite::create("Items/box_1.png"));

			isOpen = 0;
		}

	}

}
void TreasureBoxes::notice(char s[])
{
	noticeLabel = Label::createWithTTF(s, "fonts/Marker Felt.ttf", 24);
	mScene->addChild(noticeLabel, 6);
	noticeLabel->setTag(NoticeLabel_TAG);

	noticeLabel->setPosition(getPosition().x, getPosition().y + noticeLabel->getContentSize().height * 1.5);
}
void TreasureBoxes::update(float dt)
{
	if (isCanSee)
		this->getSprite()->setOpacity(255);
	else
		this->getSprite()->setOpacity(0);
	if (isUsed&&clock()-startTime>2000)
	{
		mScene->removeChildByTag(NoticeLabel_TAG);
	}
}
bool TreasureBoxes::getIsOpen()
{
	return isOpen;
}