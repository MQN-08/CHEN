#pragma once
#include"cocos2d.h"
#include"music/music.h"
USING_NS_CC;
/*ͨ�ó����࣬������ʵ��
* ����
* 1:���ֹ�����
* 2����TiledMap
*/
class NormalScene :public cocos2d::Scene
{
public:
	MusicManager* getmusicManager();
	void bindTiledMap(TMXTiledMap* map);
private:
	MusicManager* m_musicManager;
	TMXTiledMap* m_map;
};
