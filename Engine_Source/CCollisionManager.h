#pragma once
#include "CommonInclude.h"
#include "CBoxCollider2D.h"
#include "CCircleCollider2D.h"

namespace ya
{
	using namespace enums;

	union CollisionID
	{
		struct
		{
			UINT32 left;
			UINT32 right;
		};
		UINT64 id;
	};

	class CCollisionManager
	{
	private:
		static std::bitset<(UINT)LAYER_TYPE::Max>	m_CollisionLayerMatrix[(UINT)LAYER_TYPE::Max];
		static std::unordered_map<UINT64, bool>	m_CollisionMap;

	public:
		static void Init();
		static void Update();
		static void LateUpdate();
		static void Render(HDC _hDC);

		static void CollisionLayerCheck(LAYER_TYPE _eLeft, LAYER_TYPE _eRight, bool _bEnable);
		static void LayerCollision(class CScene* _pScene, LAYER_TYPE _eLeft, LAYER_TYPE _eRight);
		static void ColliderCollision(CCollider* _pLeft, CCollider* _pRight);
		static bool Intersect(CCollider* _pLeft, CCollider* _pRight);
	};
}