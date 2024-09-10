#pragma once
#include "CommonInclude.h"

namespace ya
{
	class CEntity
	{
	public:
		CEntity();
		virtual ~CEntity();

	private:
		wstring m_strName;

	public:
		void SetName(const wstring& _strName) { m_strName = _strName; }
		wstring& GetName() { return m_strName; }
	};
}