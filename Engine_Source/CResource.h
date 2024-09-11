#pragma once
#include "CEntity.h"

namespace ya
{
	class CResource abstract : public CEntity
	{
	public:
		CResource(enums::RESOURCE_TYPE _eType);
		virtual ~CResource();

	private:
		const enums::RESOURCE_TYPE	m_eResourceType;
		wstring m_strPath;

	public:
		void SetPath(const wstring& _strPath) { m_strPath = _strPath; }
		const wstring& GetPath() { return m_strPath; }

		//virtual HRESULT Save(const wstring& _strPath) = 0;
		virtual HRESULT Load(const wstring& _strPath) = 0;
	};
}