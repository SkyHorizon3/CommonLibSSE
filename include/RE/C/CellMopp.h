#pragma once

#include "RE/B/BSTaskletGroup.h"
#include "RE/B/BSWin32TaskletData.h"
#include "RE/H/hkRefPtr.h"
#include "RE/N/NiRefObject.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/N/NiTArray.h"

namespace RE
{
	class bhkRigidBody;
	class hkpTriSampledHeightFieldBvTreeShape;

	class CellMopp : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_CellMopp;
		inline static constexpr auto VTABLE = VTABLE_CellMopp;

		class HeightFieldWeldingTasklet : public BSWin32TaskletData
		{
		public:
			inline static constexpr auto RTTI = RTTI_CellMopp__HeightFieldWeldingTasklet;
			inline static constexpr auto VTABLE = VTABLE_CellMopp__HeightFieldWeldingTasklet;

			~HeightFieldWeldingTasklet() override;  // 00

			// override (BSTaskletData)
			void Process() override;  // 02

			// members
			hkRefPtr<hkpTriSampledHeightFieldBvTreeShape> shape;  // 28
		};
		static_assert(sizeof(HeightFieldWeldingTasklet) == 0x30);

		~CellMopp() override;  // 00

		// members
		BSTaskletGroup                          taskletGroup;        // 10
		HeightFieldWeldingTasklet               weldingTasklets[4];  // 18
		NiTObjectArray<NiPointer<bhkRigidBody>> rigidBodies;         // D8
	};
	static_assert(sizeof(CellMopp) == 0xF0);
}
