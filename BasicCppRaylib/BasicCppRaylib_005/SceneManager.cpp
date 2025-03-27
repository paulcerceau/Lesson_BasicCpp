#include "SceneManager.h"

SceneManager::SceneManager() :
	mCurrentState(SceneState::Menu)
{
}

SceneManager::~SceneManager()
{
}

SceneState SceneManager::GetCurrentState() const
{
	return mCurrentState;
}

void SceneManager::SetCurrentState(SceneState state)
{
	mCurrentState = state;
}

