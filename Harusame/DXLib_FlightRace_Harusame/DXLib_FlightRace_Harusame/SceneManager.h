#pragma once
namespace Scene
{
	enum SceneState
	{
		TITLE,
		GAME,
		RESULT,
	};

	class SceneManager
	{
	public:
		inline SceneManager();
		inline ~SceneManager();
		bool SceneProcess();
	private:

	};

	SceneManager::SceneManager()
	{
	}

	SceneManager::~SceneManager()
	{
	}

}