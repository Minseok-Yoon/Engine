#include "CCircleCollider2D.h"
#include "CTransform.h"
#include "CGameObject.h"
#include "CRenderer.h"
#include "CCamera.h"

namespace ya
{
	CCircleCollider2D::CCircleCollider2D() :
		CCollider(COLLIDER_TYPE::Circle2D)
	{
	}

	CCircleCollider2D::~CCircleCollider2D()
	{
	}

	void CCircleCollider2D::Init()
	{
	}

	void CCircleCollider2D::Update()
	{
	}

	void CCircleCollider2D::LateUpdate()
	{
	}

	void CCircleCollider2D::Render(HDC _hDC)
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

		math::Vector2 rightBottom;
		rightBottom.x = vPos.x + vOffset.x + 100 * GetSize().x;
		rightBottom.y = vPos.y + vOffset.y + 100 * GetSize().y;

		Ellipse(_hDC, vPos.x + vOffset.x,
			vPos.y + vOffset.y,
			rightBottom.x,
			rightBottom.y);

		SelectObject(_hDC, oldBrush);
		SelectObject(_hDC, oldPen);
		DeleteObject(greenPen);
	}
}