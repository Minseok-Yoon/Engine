#pragma once
#include "CResource.h"

namespace ya
{
	class CResources
	{
	public:
		template <typename T>
		static T* Find(const wstring& _strKey)
		{
			auto iter = m_mapResources.find(_strKey);
			if (iter == m_mapResources.end())
				return nullptr;

			return dynamic_cast<T*>(iter->second);
		}

		template <typename T>
		static T* Load(const wstring& _strKey, const wstring& _strPath)
		{
			T* resource = CResources::Find<T>(_strKey);
			if (resource != nullptr)
				return resource;

			resource = new T();
			if (FAILED(resource->Load(_strPath)))
				assert(false);

			resource->SetName(_strKey);
			resource->SetPath(_strPath);
			m_mapResources.insert(make_pair(_strKey, resource));

			return resource;
		}

	private:
		static map<wstring, CResource*> m_mapResources;
	};
}