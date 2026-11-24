#pragma once

#include "RE/B/BSTArray.h"
#include "RE/I/IMenu.h"
#include "RE/M/MenuEventHandler.h"
#include "RE/R/RaceSexCamera.h"
#include "RE/S/Sexes.h"

namespace RE
{
	class BGSHeadPart;
	class TESRace;

	// menuDepth = 3
	// flags = kPausesGame | kUsesMenuContext | kRequiresUpdate | kTopmostRenderedMenu | kUpdateUsesCursor
	// context = kItemMenu
	class RaceSexMenu :
		public IMenu,            // 00
		public MenuEventHandler  // 30
	{
	public:
		inline static constexpr auto      RTTI = RTTI_RaceSexMenu;
		inline static constexpr auto      VTABLE = VTABLE_RaceSexMenu;
		constexpr static std::string_view MENU_NAME = "RaceSex Menu";

		struct MorphSlider
		{
		public:
			// members
			float         min;                // 000
			float         max;                // 004
			float         position;           // 008
			float         interval;           // 00C
			std::uint32_t filterFlag;         // 010
			std::uint32_t type;               // 014
			const char*   text;               // 018
			char          callbackName[260];  // 020
			std::uint32_t index;              // 124
			std::uint32_t sliderID;           // 128
			std::uint32_t unk12C;             // 12C
			float         value;              // 130
			bool          unk134;             // 134
			std::uint8_t  pad135;             // 135
			std::uint16_t pad136;             // 136
		};
		static_assert(sizeof(MorphSlider) == 0x138);

		struct RaceAndSliderSet
		{
		public:
			// members
			TESRace*              race;         // 00
			BSTArray<MorphSlider> sliders;      // 08
			bool                  initialized;  // 20
			bool                  unk21;        // 21
			std::uint16_t         pad22;        // 22
			std::uint32_t         pad24;        // 24
		};
		static_assert(sizeof(RaceAndSliderSet) == 0x28);

		~RaceSexMenu() override;  // 00

		// override (IMenu)
		void               Accept(CallbackProcessor* a_processor) override;                       // 01
		void               PostCreate() override;                                                 // 02
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                         // 04
		void               AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;  // 05

		// override (MenuEventHandler)
		bool CanProcess(InputEvent* a_event) override = 0;          // 01
		bool ProcessThumbstick(ThumbstickEvent* a_event) override;  // 03
		bool ProcessMouseMove(MouseMoveEvent* a_event) override;    // 04
		bool ProcessButton(ButtonEvent* a_event) override;          // 05

		void ChangeName(const char* a_name);

		// members
		BSTArray<BGSHeadPart*>            headParts[7];               // 040
		RaceSexCamera                     camera;                     // 0E8
		BSTArray<RaceAndSliderSet>        sliderData[SEXES::kTotal];  // 140
		BSTArray<void*>                   unk170;                     // 170
		std::uint32_t                     currentRace;                // 188
		std::uint32_t                     headPresetIndex;            // 18C
		std::uint32_t                     unk190;                     // 190
		std::uint32_t                     unk194;                     // 194
		REX::TEnumSet<SEX, std::uint32_t> sex;                        // 198
		bool                              unk19C;                     // 19C
		bool                              unk19D;                     // 19D
		bool                              unk19E;                     // 19E
		bool                              unk19F;                     // 19F
		bool                              unk1A0;                     // 1A0
		bool                              unk1A1;                     // 1A1
		bool                              unk1A2;                     // 1A2
		bool                              unk1A3;                     // 1A3
		bool                              unk1A4;                     // 1A4
		bool                              unk1A5;                     // 1A5
		std::uint16_t                     pad1A6;                     // 1A6
	};
	static_assert(sizeof(RaceSexMenu) == 0x1A8);
}
