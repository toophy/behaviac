﻿// ---------------------------------------------------------------------
// THIS FILE IS AUTO-GENERATED BY BEHAVIAC DESIGNER, SO PLEASE DON'T MODIFY IT BY YOURSELF!
// ---------------------------------------------------------------------

#ifndef _BEHAVIAC_CUSTOMIZED_TYPES_H_
#define _BEHAVIAC_CUSTOMIZED_TYPES_H_

#include "behaviac/agent/agent.h"

// -------------------
// Customized structs
// -------------------

struct MsgItem
{
	behaviac::string m_Name;
	behaviac::string m_Msg;
};

BEHAVIAC_EXTEND_EXISTING_TYPE_EX(MsgItem, true);
BEHAVIAC_DECLARE_TYPE_VECTOR_HANDLER(MsgItem);

template< typename SWAPPER >
inline void SwapByteImplement(MsgItem& v)
{
	SwapByteImplement< SWAPPER >(v.m_Name);
	SwapByteImplement< SWAPPER >(v.m_Msg);
}

namespace behaviac
{
	namespace PrivateDetails
	{
		template<>
		inline bool Equal(const MsgItem& lhs, const MsgItem& rhs)
		{
			return &lhs == &rhs;
		}
	}
}

#endif // _BEHAVIAC_CUSTOMIZED_TYPES_H_
