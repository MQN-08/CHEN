#pragma once
#include "cocos2d.h"
#include"music.h"
USING_NS_CC;
/*��ʼ������
* �������
* 1���������棬��Ϸ����UI
* 2�����ð����Լ����ý���
* 3���˳�����
*/
class StartScene : public Scene
{
public:
	virtual bool init() override;//��ʼ������
	//virtual void update(float delat) override;//���º���
	void menuCloseCallBack(Ref* sender);//�رհ�ť�ص�
	void menuSetCallBack(Ref* sender);//���ð�ť�ص�
	void menuStartCallBack(Ref* sender);//��ʼ��ť�ص�
	//virtual void update(float delta);//���º���
	CREATE_FUNC(StartScene);
private:
	MusicManager* musicManager;
	int backgroundAudio;
};