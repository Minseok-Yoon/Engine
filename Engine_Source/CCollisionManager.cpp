#include "CCollisionManager.h"
#include "CScene.h"
#include "CSceneManager.h"
#include "CGameObject.h"
#include "CCollider.h"
#include "CTransform.h"

namespace ya
{
	std::bitset<(UINT)LAYER_TYPE::Max> CCollisionManager::m_CollisionLayerMatrix[(UINT)LAYER_TYPE::Max] = {};
	std::unordered_map<UINT64, bool> CCollisionManager::m_CollisionMap = {};

	void CCollisionManager::Init()
	{
		int a = 1;
		int b = a << 1;
	}

	void CCollisionManager::Update()
	{
		CScene* scene = CSceneManager::GetActiveScene();
		for (UINT row = 0; row < (UINT)LAYER_TYPE::Max; row++)
		{
			for (UINT col = 0; col < (UINT)LAYER_TYPE::Max; col++)
			{
				if (m_CollisionLayerMatrix[row][col] == true)
				{
					LayerCollision(scene, (LAYER_TYPE)row, (LAYER_TYPE)col);
				}
			}
		}
	}

	void ya::CCollisionManager::LateUpdate()
	{
	}

	void ya::CCollisionManager::Render(HDC _hDC)
	{
	}

	void ya::CCollisionManager::CollisionLayerCheck(LAYER_TYPE _eLeft, LAYER_TYPE _eRight, bool _bEnable)
	{
		int row = 0;
		int col = 0;

		if (_eLeft <= _eRight)
		{
			row = (UINT)_eLeft;
			col = (UINT)_eRight;
		}
		else
		{
			row = (UINT)_eRight;
			col = (UINT)_eLeft;
		}

		m_CollisionLayerMatrix[row][col] = _bEnable;
	}

	void ya::CCollisionManager::LayerCollision(CScene* _pScene, LAYER_TYPE _eLeft, LAYER_TYPE _eRight)
	{
		const vector<CGameObject*>& vecLefts = _pScene->GetLayer(_eLeft)->GetGameObjects();
		const vector<CGameObject*>& vecRights = _pScene->GetLayer(_eRight)->GetGameObjects();

		for (CGameObject* _pLeft : vecLefts)
		{
			if (_pLeft->IsActive() == false)
				continue;
			CCollider* leftCol = _pLeft->GetComponent<CCollider>();
			if (leftCol == nullptr)
				continue;

			for (CGameObject* _pRight : vecRights)
			{
				if (_pRight->IsActive() == false)
					continue;
				CCollider* rightCol = _pRight->GetComponent<CCollider>();
				if (rightCol == nullptr)
					continue;
				if (_pLeft == _pRight)
					continue;

				ColliderCollision(leftCol, rightCol);
			}
		}
	}

	void ya::CCollisionManager::ColliderCollision(CCollider* _pLeft, CCollider* _pRight)
	{
		CollisionID id = {};
		id.left = _pLeft->GetID();
		id.right = _pRight->GetID();

		// 이전 충돌 정보를 검색한다.
		// 만약에 충돌정보가 없는 상태라면
		// 충돌정보를 생성해준다.

		auto iter = m_CollisionMap.find(id.id);
		if (iter == m_CollisionMap.end())
		{
			m_CollisionMap.insert(std::make_pair(id.id, false));
			iter = m_CollisionMap.find(id.id);
		}

		// 충돌 체크를 해준다.
		if (Intersect(_pLeft, _pRight))
		{
			// 최초 충돌할때
			if (iter->second == false)
			{
				_pLeft->OnCollisionEnter(_pRight);
				_pRight->OnCollisionEnter(_pLeft);
				iter->second = true;
			}
			else // 이미 충돌 중
			{
				_pLeft->OnCollisionStay(_pRight);
				_pRight->OnCollisionStay(_pLeft);
			}
		}
		else
		{
			// 충돌을 하지 않은 상태
			if (iter->second == true)
			{
				_pLeft->OnCollisionExit(_pRight);
				_pRight->OnCollisionExit(_pLeft);

				iter->second = false;
			}
		}
	}

	bool CCollisionManager::Intersect(CCollider* _pLeft, CCollider* _pRight)
	{
		CTransform* leftTr = _pLeft->GetOwner()->GetComponent<CTransform>();
		CTransform* rightTr = _pRight->GetOwner()->GetComponent<CTransform>();

		math::Vector2 leftPos = leftTr->GetPosition() + _pLeft->GetOffset();
		math::Vector2 rightPos = rightTr->GetPosition() + _pRight->GetOffset();

		// size 1,1 일때 기본크기가 100픽셀
		math::Vector2 leftSize = _pLeft->GetSize() * 100.0f;
		math::Vector2 rightSize = _pRight->GetSize() * 100.0f;

		// AABB 충돌
		/*if (fabs(leftPos.x - RightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
			&& fabs(leftPos.y -  rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
		{
			return true;
		}*/

		// AABB 충돌
		COLLIDER_TYPE leftType = _pLeft->GetColliderType();
		COLLIDER_TYPE rightType = _pRight->GetColliderType();

		if (leftType == COLLIDER_TYPE::Rect2D &&
			rightType == COLLIDER_TYPE::Rect2D)
		{
			if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
				&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
			{
				return true;
			}
		}

		if (leftType == COLLIDER_TYPE::Circle2D &&
			rightType == COLLIDER_TYPE::Circle2D)
		{
			math::Vector2 leftCirclePos = leftPos + (leftSize / 2.0f);
			math::Vector2 rightCirclePos = rightPos + (rightSize / 2.0f);
			float distance = (leftCirclePos - rightCirclePos).length();
			if (distance <= (leftSize.x / 2.0f + rightSize.x / 2.0f))
			{
				return true;
			}
		}

		if ((leftType == COLLIDER_TYPE::Circle2D && rightType == COLLIDER_TYPE::Rect2D) ||
			(leftType == COLLIDER_TYPE::Rect2D && rightType == COLLIDER_TYPE::Circle2D))
		{

		}

		return false;
	}
}