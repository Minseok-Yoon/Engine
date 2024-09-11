#pragma once
#include "CommonInclude.h"
#include "CComponenet.h"

namespace ya
{
	class CGameObject
	{
	public:
		CGameObject();
		~CGameObject();

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Init();
			comp->SetOwner(this);
			m_vecComponents.push_back(comp);

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (CComponenet* comp : m_vecComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}
			return component;
		}

	private:
		vector<CComponenet*> m_vecComponents;
		enums::LAYER_TYPE	m_eLayerType;

	public:
		void SetLayerType(const enums::LAYER_TYPE _eLayerType) { m_eLayerType = _eLayerType; }
		enums::LAYER_TYPE GetLayerType() const { return m_eLayerType; }

	public:
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hDC);
	};
}