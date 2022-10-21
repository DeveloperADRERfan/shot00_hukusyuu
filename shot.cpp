#include "DxLib.h"
#include "shot.h"
#include "game.h"
#include "enemy.h"
#include "player.h"


Shot::Shot()	: 
	m_handle(-1),		// ƒRƒ“ƒXƒgƒ‰ƒNƒ^‰Šú‰»’l
	m_isExist(false),
	m_pos(100.0f, 100.0f),
	m_vec(8.0f, 0.0f),
	m_isPlayerShot(false)
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

// ”­ŽË
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
// •\Ž¦
void Shot::draw()
{
	if (!m_isExist) return;

	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}

// “G‚Æ‚Ì“–‚½‚è”»’è
bool Shot::isEnemyCol(Enemy& enemy)
{
	// “G‚ÌŒ‚‚Á‚½’e‚Í“–‚½‚ç‚È‚¢
	if (!m_isPlayerShot)	return false;

	// ‘¶Ý‚µ‚È‚¢“GA‘¶Ý‚µ‚È‚¢’e‚Í‰½‚à“–‚½‚ç‚È‚¢
	if (!m_isExist) return false;
	if (!enemy.isExist()) return false;

	float shotWidth = 0;
	float shotHeight = 0;
	GetGraphSizeF(m_handle, &shotWidth, &shotHeight);

	float shotLeft = m_pos.x;
	float shotTop = m_pos.y;
	float shotRight = m_pos.x + shotWidth;
	float shotBottom = m_pos.y + shotHeight;

	float enemyLeft = enemy.getPos().x;
	float enemyTop = enemy.getPos().y;
	float enemyRight = enemy.getPos().x + enemy.getColWidth();
	float enemyBottom = enemy.getPos().y + enemy.getColHeight();

	if (enemyLeft > shotRight) return false;
	if (enemyRight < shotLeft) return false;
	if (enemyTop > shotBottom) return false;
	if (enemyBottom < shotTop) return false;

	return true;
}

bool Shot::isPlayerCol(Player& player)
{
	// ƒvƒŒƒCƒ„[‚ÌŒ‚‚Á‚½’e‚Í“–‚½‚ç‚È‚¢
	if (!m_isEnemyShot)	return false;

	// ‘¶Ý‚µ‚È‚¢“GA‘¶Ý‚µ‚È‚¢’e‚Í‰½‚à“–‚½‚ç‚È‚¢
	if (!m_isExist) return false;
	if (!player.isExist()) return false;

	float shotWidth = 0;
	float shotHeight = 0;
	GetGraphSizeF(m_handle, &shotWidth, &shotHeight);

	float shotLeft = m_pos.x;
	float shotTop = m_pos.y;
	float shotRight = m_pos.x + shotWidth;
	float shotBottom = m_pos.y + shotHeight;

	float playerLeft = player.getPos().x;
	float playerTop = player.getPos().y;
	float playerRight = player.getPos().x + player.getColWidth();
	float playerBottom = player.getPos().y + player.getColHeight();

	if (playerLeft > shotRight) return false;
	if (playerRight < shotLeft) return false;
	if (playerTop > shotBottom) return false;
	if (playerBottom < shotTop) return false;

	return true;
}


