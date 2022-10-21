#include "DxLib.h"
#include "SceneMain.h"

SceneMain::SceneMain():
	m_hPlayerGraphic(-1),
	m_hShotGraphic(-1),
	m_player(),
	m_enemy(),
	m_shot()
{
	m_shot.resize(kShotMax);
}

SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");
	m_hShotGraphic = LoadGraph("data/shot.bmp");

	m_player.setMain(this);		// 自身のポインタを渡す場合はthis
	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();

	m_enemy.setMain(this);
	m_enemy.setHandle(m_hPlayerGraphic);
	m_enemy.init();

	for (auto& shot : m_shot)
	{
		shot.setHandle(m_hShotGraphic);
	}
}

// 終了処理
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);
}

// 毎フレームの処理
void SceneMain::update()
{
	m_player.update();
	m_enemy.update();
	for (auto& shot : m_shot)
	{
		shot.update();
		if (shot.isEnemyCol(m_enemy))	// shotの持つisCol関数　どいつと当たるか　e_enemy
		{
			// 当たっている場合の処理
			m_enemy.setExist(false);
		}

		if (shot.isPlayerCol(m_player))	// shotの持つisCol関数　どいつと当たるか　e_player
		{
			// 当たっている場合の処理
			m_player.setExist(false);
		}
	}

	// キー入力処理
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_1)
	{
	}
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();
	m_enemy.draw();

	for (auto& shot : m_shot)
	{
		shot.draw();
	}
}

// ショットを撃つ
bool SceneMain::createShot(Vec2 pos, bool isPlayer)
{
	for (auto& shot : m_shot)
	{
		if (!shot.isExist())
		{
			shot.start(pos);
			Vec2 vec{ 8.0f, 0.0f };
			if (!isPlayer)
			{
				vec.x *= -1.0f;
			}
			shot.setVec(vec);
			shot.setPlayerShot(isPlayer);

			return true;
		}

	}
	return false;

	for (auto& shot : m_shot)
	{
		if()
	}
}