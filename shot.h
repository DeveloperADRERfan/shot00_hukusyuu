#pragma once
#include "Vec2.h"

class Enemy;
class Player;

class Shot
{
public:
	Shot();
	virtual ~Shot();

	void setHandle(int handle) { m_handle = handle; }

	// 発射
	void start(Vec2 pos);

	// 更新
	void update();
	// 表示
	void draw();

	// 弾の進行方向決定
	void setVec(Vec2 vec) { m_vec = vec; }

	// 存在するか
	bool isExist() const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist ; }

	// プレイヤーが撃った弾かどうか
	bool isPlayerShot() const { return m_isPlayerShot; }
	void setPlayerShot(bool isPlayerShot) { m_isPlayerShot = isPlayerShot; }

	// プレイヤーが撃った弾かどうか
	bool isEnemyShot() const { return m_isEnemyShot; }
	void setEnemyShot(bool isEnemyShot) { m_isEnemyShot = isEnemyShot; }

	// プレイヤーとの当たり判定
	bool isPlayerCol(Player& player);

	// 敵との当たり判定
	bool isEnemyCol(Enemy& enemy);
	

private:
	// グラフィックハンドル
	int m_handle;
	// 存在フラグ
	bool m_isExist;

	// 表示位置
	Vec2	m_pos;
	// 移動
	Vec2	m_vec;
	// プレイヤーが撃った弾かどうか
	bool m_isPlayerShot;
	// 敵が撃った弾かどうか
	bool m_isEnemyShot;

};