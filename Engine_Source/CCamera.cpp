#include "CCamera.h"
#include "CApplication.h"
#include "CGameObject.h"
#include "CTransform.h"

extern ya::CApplication application;

namespace ya
{
	CCamera::CCamera() :
		CComponent(enums::COMPONENT_TYPE::Camera),
		m_vDistance(math::Vector2::Zero),
		m_vResolution(math::Vector2::Zero),
		m_vLookPosition(math::Vector2::Zero),
		m_pTarget(nullptr)
	{
	}

	CCamera::~CCamera()
	{
	}

	void CCamera::Init()
	{
		m_vResolution.x = application.GetWidth();
		m_vResolution.y = application.GetHeight();
	}

	void CCamera::Update()
	{
		if (m_pTarget)
		{
			CTransform* tr = m_pTarget->GetComponent<CTransform>();
			m_vLookPosition = tr->GetPosition();
		}

		CTransform* cameraTr = GetOwner()->GetComponent<CTransform>();
		m_vLookPosition = cameraTr->GetPosition();

		m_vDistance = m_vLookPosition - (m_vResolution / 2.0f);
	}

	void CCamera::LateUpdate()
	{
	}

	void CCamera::Render(HDC _hDC)
	{
	}
}