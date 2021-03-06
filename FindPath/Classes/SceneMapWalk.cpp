#include "SceneMapWalk.h"
#include "LayerMapWalk.h"
#include "LayerHudControl.h"

SceneMapWalk::SceneMapWalk()
{
}

SceneMapWalk::~SceneMapWalk()
{
}

bool SceneMapWalk::init()
{
	m_pLayerMapWalk = LayerMapWalk::create();
	this->addChild(m_pLayerMapWalk);

	auto pLayerHudControl = LayerHudControl::create();
	this->addChild(pLayerHudControl);

	pLayerHudControl->m_pLayerMapWalk = m_pLayerMapWalk;

	return true;
}
