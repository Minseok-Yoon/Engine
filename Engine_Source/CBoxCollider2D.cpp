#include "CBoxCollider2D.h"
#include "CTransform.h"
#include "CGameObject.h"
#include "CRenderer.h"
#include "CCamera.h"

namespace ya
{
	CBoxCollider2D::CBoxCollider2D() :
		CCollider(COLLIDER_TYPE::Rect2D)
	{
	}

	CBoxCollider2D::~CBoxCollider2D()
	{
	}

	void CBoxCollider2D::Init()
	{
	}

	void CBoxCollider2D::Update()
	{
	}

	void CBoxCollider2D::LateUpdate()
	{
	}

	void CBoxCollider2D::Render(HDC _hDC)
	{
		CTransform* tr = GetOwner()->GetComponent<CTransform>();
		math::Vector2 vPos = tr->GetPosition();

		if (renderer::mainCamera)
			vPos = renderer::mainCamera->CaluatePosition(vPos);

		math::Vector2 vOffset = GetOffset();
		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(_hDC, transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(_hDC, greenPen);

		Rectangle(_hDC, vPos.x + vOffset.x, 
			vPos.y + vOffset.y, 
			vPos.x + vOffset.x + 100 * GetSize().x, 
			vPos.y + vOffset.y + 100 * GetSize().y);

			SelectObject(_hDC, oldBrush);
			SelectObject(_hDC, oldPen);
	}
}