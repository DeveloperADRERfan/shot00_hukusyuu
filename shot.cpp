#include "DxLib.h"
#include "shot.h"
#include "game.h"


Shot::Shot()	: 
	m_handle(-1),		// コンストラクタ初期化値
	m_isExist(false),
	m_pos(100.0f, 100.0f),
	m_vec(8.0f, 0.0f)
{
//	m_handle = -1;
//	m_isExist = false;

//	m_pos.x = 100.0f;
//	m_pos.y = 100.0f;

//	m_vec.x = 8.0f;
//	m_vec.y = 0.0f;
}

Shot::~Shot()
{

}

// 発射
void Shot::start(Vec2 pos)
{
	m_isExist = true;
	m_pos = pos;
}

void Shot::update()
{
	if (!m_isExist) return;

	m_pos += m_vec;
	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}
}
// 表示
void Shot::draw()
{
	if (!m_isExist) return;

	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}
