namespace Hooks
{
	class hkSaveGame :
		public REX::Singleton<hkSaveGame>
	{
	private:
		static bool SaveGame(void* a_this, void* a_file, const char* a_fileName, bool a_logStats)
		{
			if (a_fileName && !_stricmp(a_fileName, "quicksave"))
			{
				a_fileName = nullptr;
			}
			return _SaveGame00(a_this, a_file, a_fileName, a_logStats);
		}

		inline static REL::Hook _SaveGame00{ REL::ID(405145), 0x050, SaveGame };
		inline static REL::Hook _SaveGame01{ REL::ID(405249), 0x031, SaveGame };
		inline static REL::Hook _SaveGame02{ REL::ID(409582), 0x056, SaveGame };
		inline static REL::Hook _SaveGame03{ REL::ID(409667), 0x00C, SaveGame };
		inline static REL::Hook _SaveGame04{ REL::ID(409710), 0x1CC, SaveGame };
		inline static REL::Hook _SaveGame05{ REL::ID(411233), 0x096, SaveGame };
		inline static REL::Hook _SaveGame06{ REL::ID(411246), 0x252, SaveGame };
		inline static REL::Hook _SaveGame07{ REL::ID(411247), 0x023, SaveGame };
		inline static REL::Hook _SaveGame08{ REL::ID(421554), 0x157, SaveGame };
	};

	class hkQuickLoad :
		public REX::Singleton<hkQuickLoad>
	{
	private:
		static void RequestLoadLastSaveGame(void* a_this)
		{
			using func_t = decltype(&RequestLoadLastSaveGame);
			static REL::Relocation<func_t> func{ REL::ID(308794) };
			return func(a_this);
		}

		static void RequestQuickLoad(void* a_this)
		{
			return RequestLoadLastSaveGame(a_this);
		}

		inline static REL::Hook _RequestQuickLoad{ REL::ID(308184), 0xC6, RequestQuickLoad };
	};

	class hkQuickLoadCheck :
		public REX::Singleton<hkQuickLoadCheck>
	{
	private:
		static void GetSlotNameFromIndex(void* a_this, void* a_slotName, std::int32_t a_slotIndex)
		{
			using func_t = decltype(&GetSlotNameFromIndex);
			static REL::Relocation<func_t> func{ REL::ID(308656) };
			return func(a_this, a_slotName, a_slotIndex);
		}

		static bool DoesSaveExist(void* a_this, void* a_slotName)
		{
			GetSlotNameFromIndex(a_this, a_slotName, 0);
			return _DoesSaveExist(a_this, a_slotName);
		}

		inline static REL::Hook _DoesSaveExist{ REL::ID(308795), 0x32, DoesSaveExist };
	};
}

OBSE_PLUGIN_LOAD(const OBSE::LoadInterface* a_obse)
{
	OBSE::Init(a_obse, { .trampoline = true, .trampolineSize = 64 });
	return true;
}
