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

	public:
		virtual void Init();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC _hDC);
	};
}