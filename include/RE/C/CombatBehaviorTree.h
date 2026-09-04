#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/C/CombatBehaviorTreeNodeObject.h"

namespace RE
{
	class Actor;
	class CombatBehaviorTreeNode;

	class CombatBehaviorTree
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatBehaviorTree;
		inline static constexpr auto VTABLE = VTABLE_CombatBehaviorTree;

		class TreeBuilder
		{
		public:
			TreeBuilder* AppendLastNode(const TreeBuilder& a_other);

			// members
			BSTArray<CombatBehaviorTreeNode*> nodeArray;  // 00
		};
		static_assert(sizeof(TreeBuilder) == 0x18);

		virtual void Initialize();  // 00

		void CreateTree(CombatBehaviorTreeNode* a_node);

		static TreeBuilder* AddNode(TreeBuilder* a_out, const char* a_name, CombatBehaviorTreeNode* a_node);
		static Actor*       GetAttacker();
		static Actor*       GetTarget();

		template <class T>
		static T* CreateObject()
		{
			static_assert(sizeof(CombatBehaviorTreeNodeObject<T>) == 0x28);
			auto obj = malloc<CombatBehaviorTreeNodeObject<T>>();
			if (obj) {
				std::memset(obj, 0, sizeof(CombatBehaviorTreeNodeObject<T>));
				obj->Ctor();  // CombatBehaviorTreeNode::Ctor
				REX::EMPLACE_VTABLE(obj);
			}
			return obj;
		}

		// members
		BSFixedString           name;  // 08
		CombatBehaviorTreeNode* root;  // 10
	};
	static_assert(sizeof(CombatBehaviorTree) == 0x18);
}
