#include "CDestroy.h"
#include "CGameObject.h"

namespace ya
{
	void Destroy(CGameObject* _pObj)
	{
		_pObj->Death();
	}
}