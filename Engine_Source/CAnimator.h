#pragma once
#include "CComponent.h"
#include "CAnimation.h"

namespace ya
{
	class CAnimator : public CComponent
	{
	public:
		struct Event
		{
			void operator=(function<void()> func)
			{
				m_mapEvents = move(func);
			}

			void operator()()
			{
				if (m_mapEvents)
					m_mapEvents();
			}

			function<void()> m_mapEvents;
		};

		struct Events
		{
			Event tStartEvent;
			Event tComplateEvent;
			Event tEndEvent;
		};

		CAnimator();
		virtual ~CAnimator();

	private:
		map<wstring, CAnimation*> m_mapAnimations;
		CAnimation* m_pActiveAnimation;
		bool	m_bLoop;

		map<wstring, Events*> m_mapEvents;

	public:
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hDC);

		void CreateAnimation(const wstring& _strName,
			graphics::CTexture* _pSpriteSheet,
			math::Vector2 _vLeftTop,
			math::Vector2 _vSize,
			math::Vector2 _vOffset,
			UINT _iSpriteLength,
			float _fDuration);
		void CreateAnimationByFolder(const wstring& _strName,
			const wstring& _strPath, math::Vector2 _vOffset, float _fDuration);

		CAnimation* FindAnimation(const wstring& _strName);
		void PlayAnimation(const wstring& _strName, bool _bLoop = true);
		bool IsComplete() { return m_pActiveAnimation->IsComplete(); }

		Events* FindEvents(const wstring& _strName);
		function<void()>& GetStartEvent(const wstring& _strName);
		function<void()>& GetCompleteEvent(const wstring& _strName);
		function<void()>& GetEndEvent(const wstring& _strName);
	};
}