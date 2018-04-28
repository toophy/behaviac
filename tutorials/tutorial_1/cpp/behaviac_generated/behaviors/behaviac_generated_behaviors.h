﻿// ---------------------------------------------------------------------
// THIS FILE IS AUTO-GENERATED BY BEHAVIAC DESIGNER, SO PLEASE DON'T MODIFY IT BY YOURSELF!
// ---------------------------------------------------------------------

#ifndef _BEHAVIAC_GENERATED_BEHAVIORS_H_
#define _BEHAVIAC_GENERATED_BEHAVIORS_H_

#include "../types/behaviac_types.h"

namespace behaviac
{
	// Source file: FirstBT

	class Action_bt_FirstBT_node0 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_FirstBT_node0, Action);
		Action_bt_FirstBT_node0()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			((FirstAgent*)pAgent)->SayHello();
			return BT_SUCCESS;
		}
	};

	class bt_FirstBT
	{
	public:
		static bool Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("FirstBT");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("FirstAgent");
#endif
			// children
			{
				Action_bt_FirstBT_node0* node0 = BEHAVIAC_NEW Action_bt_FirstBT_node0;
				node0->SetClassNameString("Action");
				node0->SetId(0);
#if !BEHAVIAC_RELEASE
				node0->SetAgentType("FirstAgent");
#endif
				pBT->AddChild(node0);
				pBT->SetHasEvents(pBT->HasEvents() | node0->HasEvents());
			}
			return true;
		}
	};

	// Source file: SecondBT

	class Assignment_bt_SecondBT_node6 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_SecondBT_node6, Assignment);
		Assignment_bt_SecondBT_node6()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::string opr = ((SecondAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_SecondAgent_m_RandomTarget, behaviac::string >();
			((SecondAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_SecondAgent_m_OldRandomTarget, behaviac::string >() = opr;
			return result;
		}
	};

	class Assignment_bt_SecondBT_node5 : public Assignment
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Assignment_bt_SecondBT_node5, Assignment);
		Assignment_bt_SecondBT_node5()
		{
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			EBTStatus result = BT_SUCCESS;
			behaviac::string opr = ((SecondAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_SecondAgent_RandomTarget, behaviac::string >();
			((SecondAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_SecondAgent_m_RandomTarget, behaviac::string >() = opr;
			return result;
		}
	};

	class Action_bt_SecondBT_node0 : public Action
	{
	public:
		BEHAVIAC_DECLARE_DYNAMIC_TYPE(Action_bt_SecondBT_node0, Action);
		Action_bt_SecondBT_node0()
		{
			method_p1 = (char*)("你好");
		}
	protected:
		virtual EBTStatus update_impl(Agent* pAgent, EBTStatus childStatus)
		{
			BEHAVIAC_UNUSED_VAR(pAgent);
			BEHAVIAC_UNUSED_VAR(childStatus);
			behaviac::string method_p0 = ((SecondAgent*)pAgent)->_Get_Property_<PROPERTY_TYPE_SecondAgent_m_RandomTarget, behaviac::string >();
			((SecondAgent*)pAgent)->_Execute_Method_<METHOD_TYPE_SecondAgent_SayTo, void, behaviac::string, behaviac::string >(method_p0, method_p1);
			return BT_SUCCESS;
		}
		behaviac::string method_p1;
	};

	class bt_SecondBT
	{
	public:
		static bool Create(BehaviorTree* pBT)
		{
			pBT->SetClassNameString("BehaviorTree");
			pBT->SetId((uint16_t)-1);
			pBT->SetName("SecondBT");
			pBT->SetIsFSM(false);
#if !BEHAVIAC_RELEASE
			pBT->SetAgentType("SecondAgent");
#endif
			// children
			{
				Sequence* node1 = BEHAVIAC_NEW Sequence;
				node1->SetClassNameString("Sequence");
				node1->SetId(1);
#if !BEHAVIAC_RELEASE
				node1->SetAgentType("SecondAgent");
#endif
				pBT->AddChild(node1);
				{
					Assignment_bt_SecondBT_node6* node6 = BEHAVIAC_NEW Assignment_bt_SecondBT_node6;
					node6->SetClassNameString("Assignment");
					node6->SetId(6);
#if !BEHAVIAC_RELEASE
					node6->SetAgentType("SecondAgent");
#endif
					node1->AddChild(node6);
					node1->SetHasEvents(node1->HasEvents() | node6->HasEvents());
				}
				{
					Assignment_bt_SecondBT_node5* node5 = BEHAVIAC_NEW Assignment_bt_SecondBT_node5;
					node5->SetClassNameString("Assignment");
					node5->SetId(5);
#if !BEHAVIAC_RELEASE
					node5->SetAgentType("SecondAgent");
#endif
					node1->AddChild(node5);
					node1->SetHasEvents(node1->HasEvents() | node5->HasEvents());
				}
				{
					Action_bt_SecondBT_node0* node0 = BEHAVIAC_NEW Action_bt_SecondBT_node0;
					node0->SetClassNameString("Action");
					node0->SetId(0);
#if !BEHAVIAC_RELEASE
					node0->SetAgentType("SecondAgent");
#endif
					node1->AddChild(node0);
					node1->SetHasEvents(node1->HasEvents() | node0->HasEvents());
				}
				pBT->SetHasEvents(pBT->HasEvents() | node1->HasEvents());
			}
			return true;
		}
	};

}
#endif // _BEHAVIAC_GENERATED_BEHAVIORS_H_