#pragma once

#include "RE/C/CombatBehaviorTreeNodeObjectBase.h"

namespace RE
{
	template <class T>
	class CombatBehaviorTreeNodeObject : public CombatBehaviorTreeNodeObjectBase<T>
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatBehaviorTreeNodeObject<T>;
		inline static constexpr auto VTABLE = VTABLE_CombatBehaviorTreeNodeObject<T>;

		~CombatBehaviorTreeNodeObject() override = default;  // 00

		// override (CombatBehaviorTreeNodeObjectBase<T>)
		void Enter(CombatBehaviorThread* a_thread) override;  // 02
	};

#define REGISTER_COMBAT_BEHAVIOR(Type)                                                                      \
	template <>                                                                                             \
	inline constexpr auto CombatBehaviorTreeNodeObject<Type> = RTTI_CombatBehaviorTreeNodeObject_##Type##_; \
	template <>                                                                                             \
	inline constexpr auto CombatBehaviorTreeNodeObject<Type> = VTABLE_CombatBehaviorTreeNodeObject_##Type##_;
}
