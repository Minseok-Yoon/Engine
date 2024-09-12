#include "CAnimator.h"

namespace ya
{
	CAnimator::CAnimator() :
		CComponent(enums::COMPONENT_TYPE::Animator),
		m_mapAnimations{},
		m_pActiveAnimation(nullptr),
		m_bLoop(false)
	{
	}

	CAnimator::~CAnimator()
	{
	}

	void CAnimator::Init()
	{
	}

	void CAnimator::Update()
	{
		if (m_pActiveAnimation)
		{
			m_pActiveAnimation->Update();

			if (m_pActiveAnimation->IsComplete() == true
				&& m_bLoop = true)
			{
				m_pActiveAnimation->Reset();
			}
		}
	}

	void CAnimator::LateUpdate()
	{
	}

	void CAnimator::Render(HDC _hDC)
	{
		if (m_pActiveAnimation)
			m_pActiveAnimation->Render(_hDC);
	}

	void CAnimator::CreateAnimation(const wstring& _strName, graphcis::CTexture* _pSpriteSheet, 
		math::Vector2 _vLeftTop, math::Vector2 _vSize, math::Vector2 _vOffset, 
		UINT _iSpriteLength, float _fDuration)
	{
		CAnimation* animation = nullptr;
		animation = FindAnimation(_strName);
		if (animation != nullptr)
			return;

		animation = new CAnimation();
		animation->CreateAnimation(_strName, _pSpriteSheet, _vLeftTop,
			_vSize, _vOffset, _iSpriteLength, _fDuration);

		animation->SetAnimator(this);

		m_mapAnimations.insert(make_pair(_strName, animation));
	}

	CAnimation* CAnimator::FindAnimation(const wstring& _strName)
	{
		auto iter = m_mapAnimations.find(_strName);
		if (iter == m_mapAnimations.end())
			return nullptr;

		return iter->second;
	}

	void CAnimator::PlayAnimation(const wstring& _strName, bool _bLoop)
	{
		CAnimation* animation = FindAnimation(_strName);
		if (animation == nullptr)
			return;

		m_pActiveAnimation = animation;
		m_pActiveAnimation->Reset();
		m_bLoop = _bLoop;
	}
}