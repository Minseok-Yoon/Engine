#include "CAnimator.h"
#include "CResources.h"
#include "CTexture.h"

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
		for (auto& iter : m_mapAnimations)
		{
			delete iter.second;
			iter.second = nullptr;
		}

		for (auto& iter : m_mapEvents)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	void CAnimator::Init()
	{
	}

	void CAnimator::Update()
	{
		if (m_pActiveAnimation)
		{
			m_pActiveAnimation->Update();

			Events* events = FindEvents(m_pActiveAnimation->GetName());

			if (m_pActiveAnimation->IsComplete() == true)
			{
				if (events)
					events->tComplateEvent();

				if(m_bLoop == true)
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

	void CAnimator::CreateAnimation(const wstring& _strName, graphics::CTexture* _pSpriteSheet, 
		math::Vector2 _vLeftTop, math::Vector2 _vSize, math::Vector2 _vOffset, 
		UINT _iSpriteLength, float _fDuration)
	{
		CAnimation* animation = nullptr;
		animation = FindAnimation(_strName);
		if (animation != nullptr)
			return;

		animation = new CAnimation();
		animation->SetName(_strName);
		animation->CreateAnimation(_strName, _pSpriteSheet, _vLeftTop,
			_vSize, _vOffset, _iSpriteLength, _fDuration);

		animation->SetAnimator(this);

		Events* events = new Events();
		m_mapEvents.insert(make_pair(_strName, events));

		m_mapAnimations.insert(make_pair(_strName, animation));
	}

	void CAnimator::CreateAnimationByFolder(const wstring& _strName, const wstring& _strPath, 
		math::Vector2 _vOffset, float _fDuration)
	{
		CAnimation* animation = nullptr;
		animation = FindAnimation(_strName);
		if (animation != nullptr)
			return;

		int fileCount = 0;
		std::filesystem::path fs(_strPath);
		vector<graphics::CTexture*> images = {};
		for (auto& p : std::filesystem::recursive_directory_iterator(fs))
		{
			wstring fileName = p.path().filename();
			wstring fullName = p.path();

			graphics::CTexture* texture = CResources::Load<graphics::CTexture>(fileName, fullName);
			images.push_back(texture);
			fileCount++;
		}

		UINT sheetWidth = images[0]->GetWidth() * fileCount;
		UINT sheetHeight = images[0]->GetHeight();
		graphics::CTexture* spriteSheet = graphics::CTexture::Create(_strName, sheetWidth, sheetHeight);

		UINT imageWidth = images[0]->GetWidth();
		UINT imageHeight = images[0]->GetHeight();

		for (size_t i = 0; i < images.size(); i++)
		{
			BitBlt(spriteSheet->GetHdc(), i * imageWidth, 0,
				imageWidth, imageHeight, images[i]->GetHdc(), 0, 0, SRCCOPY);
		}

		CreateAnimation(_strName, spriteSheet,
			math::Vector2(0.0f, 0.0f), math::Vector2(imageWidth, imageHeight),
			_vOffset, fileCount, _fDuration);
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

		if (m_pActiveAnimation)
		{
			Events* currentEvents = FindEvents(m_pActiveAnimation->GetName());

			if (currentEvents)
				currentEvents->tEndEvent();
		}

		Events* nextEvents = FindEvents(animation->GetName());

		if (nextEvents)
			nextEvents->tStartEvent();

		m_pActiveAnimation = animation;
		m_pActiveAnimation->Reset();
		m_bLoop = _bLoop;
	}


	CAnimator::Events* CAnimator::FindEvents(const wstring& _strName)
	{
		auto iter = m_mapEvents.find(_strName);
		if (iter == m_mapEvents.end())
			return nullptr;

		return iter->second;
	}

	function<void()>& CAnimator::GetStartEvent(const wstring& _strName)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		Events* events = FindEvents(_strName);
		return events->tStartEvent.m_mapEvents;
	}

	function<void()>& CAnimator::GetCompleteEvent(const wstring& _strName)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		Events* events = FindEvents(_strName);
		return events->tComplateEvent.m_mapEvents;
	}

	function<void()>& CAnimator::GetEndEvent(const wstring& _strName)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		Events* events = FindEvents(_strName);
		return events->tEndEvent.m_mapEvents;
	}
}