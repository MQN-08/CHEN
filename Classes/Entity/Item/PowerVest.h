#pragma once
#include"Item.h"
//����ҩˮ�����˺�
USING_NS_CC;
class PowerVest :public Item
{
public:
	virtual bool init();
	virtual void update(float dt);
	virtual void Interact(int mode);

	CREATE_FUNC(PowerVest);
private:

};