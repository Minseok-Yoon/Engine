#include "CSpriteRenderer.h"
#include "CTransform.h"
#include "CGameObject.h"

namespace ya
{
	CSpriteRenderer::CSpriteRenderer()
	{
	}

	CSpriteRenderer::~CSpriteRenderer()
	{
	}

	void CSpriteRenderer::Init()
	{
	}

	void CSpriteRenderer::Update()
	{
	}

	void CSpriteRenderer::LateUpdate()
	{
	}

	void CSpriteRenderer::Render(HDC _hDC)
	{
		CTransform* tr = GetOwner()->GetComponent<CTransform>();
	}
}
