#pragma once
#include"cocos2d.h"
USING_NS_CC;
/*
* ����ʵ���࣬������ʵ��
* ����
* �󶨾���
*/
class Entity : public cocos2d::Node
{
public:
	Sprite* getSprite();
	void bindSprite(Sprite* sprite);
private:
	Sprite* m_sprite;
};