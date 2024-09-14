#pragma once
#include "CommonInclude.h"
#include "CComponent.h"
#include "CCollider.h"

namespace ya
{
	class CGameObject
	{
	public:
		enum class STATE
		{
			Active,
			Paused,
			Dead,
			End
		};

		CGameObject();
		~CGameObject();

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Init();
			comp->SetOwner(this);
			m_vecComponents[(UINT)comp->GetComponentType()] = comp;

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (CComponent* comp : m_vecComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}
			return component;
		}

	private:
		vector<CComponent*> m_vecComponents;
		enums::LAYER_TYPE	m_eLayerType;
		STATE m_eState;

	public:
		void SetLayerType(const enums::LAYER_TYPE _eLayerType) { m_eLayerType = _eLayerType; }
		enums::LAYER_TYPE GetLayerType() const { return m_eLayerType; }
		STATE GetState() { return m_eState; }
		void SetActive(bool _bPower)
		{
			if (_bPower == true) m_eState = STATE::Active;
			if (_bPower == false) m_eState = STATE::Paused;
		}
		bool IsActive() { return m_eState == STATE::Active; }
		bool IsDead() { return m_eState == STATE::Dead; }
		void Death() { m_eState = STATE::Dead; }

	public:
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hDC);

	private:
		void initializeTransform();
	};
}