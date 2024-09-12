#include "CTransform.h"

namespace ya
{
	CTransform::CTransform() :
		CComponent(enums::COMPONENT_TYPE::Transform),
		m_vScale(math::Vector2::One),
		m_fRotation(0.0f)
	{
	}

	CTransform::~CTransform()
	{
	}

	void CTransform::Init()
	{
	}

	void CTransform::Update()
	{
	}

	void CTransform::LateUpdate()
	{
	}

	void CTransform::Render(HDC _hDC)
	{
	}
}