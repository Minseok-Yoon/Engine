#include "CScript.h"
#include "CCollider.h"

namespace ya
{
	CScript::CScript() :
		CComponent(enums::COMPONENT_TYPE::Script)
	{
	}

	CScript::~CScript()
	{
	}

	void CScript::Init()
	{
	}

	void CScript::Update()
	{
	}

	void CScript::LateUpdate()
	{
	}

	void CScript::Render(HDC _hDC)
	{
	}
	void CScript::OnCollisionEnter(CCollider* _pOther)
	{
	}
	void CScript::OnCollisionStay(CCollider* _pOther)
	{
	}
	void CScript::OnCollisionExit(CCollider* _pOther)
	{
	}
}