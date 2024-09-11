#include "CComponent.h"

namespace ya
{
	CComponent::CComponent(enums::COMPONENT_TYPE _eComponentType) :
		m_eComponentType(_eComponentType)
	{
	}

	CComponent::~CComponent()
	{
	}

	void CComponent::Init()
	{
	}

	void CComponent::Update()
	{
	}

	void CComponent::LateUpdate()
	{
	}

	void CComponent::Render(HDC _hDC)
	{
	}
}