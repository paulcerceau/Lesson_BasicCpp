#pragma once

enum class SceneState
{
	Default,
	Menu,
	TwoPlayersGamemode,
	Score
};

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	SceneState GetCurrentState() const;
	void SetCurrentState(SceneState state);

private:
	SceneState mCurrentState;
};

