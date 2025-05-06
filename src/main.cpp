namespace Hooks
{
	class hkSaveGame
	{
	public:
		static bool SaveGame(void* a_this, void* a_file, const char* a_fileName, bool a_logStats)
		{
			if (a_fileName && !_stricmp(a_fileName, "quicksave")) {
				a_fileName = nullptr;
			}
			return _SaveGame00(a_this, a_file, a_fileName, a_logStats);
		}

		inline static REL::Hook _SaveGame00{ REL::Offset(0x65975F0), 0x050, SaveGame };
		inline static REL::Hook _SaveGame01{ REL::Offset(0x659AB40), 0x031, SaveGame };
		inline static REL::Hook _SaveGame02{ REL::Offset(0x672CD10), 0x056, SaveGame };
		inline static REL::Hook _SaveGame03{ REL::Offset(0x673FB30), 0x00C, SaveGame };
		inline static REL::Hook _SaveGame04{ REL::Offset(0x6745DD0), 0x1CC, SaveGame };
		inline static REL::Hook _SaveGame05{ REL::Offset(0x67D8630), 0x096, SaveGame };
		inline static REL::Hook _SaveGame06{ REL::Offset(0x67D99D0), 0x252, SaveGame };
		inline static REL::Hook _SaveGame07{ REL::Offset(0x67D9D20), 0x023, SaveGame };
		inline static REL::Hook _SaveGame08{ REL::Offset(0x6A3DEA0), 0x157, SaveGame };
	};

	class hkQuickLoad
	{
	public:
		static void RequestLoadLastSaveGame(void* a_this)
		{
			using func_t = decltype(&RequestLoadLastSaveGame);
			static REL::Relocation<func_t> func{ REL::Offset(0x48E63F0) };
			return func(a_this);
		}

		static void RequestQuickLoad(void* a_this)
		{
			return RequestLoadLastSaveGame(a_this);
		}

		inline static REL::Hook _RequestQuickLoad{ REL::Offset(0x49A54D0), 0x186, RequestQuickLoad };
	};
}

OBSE_PLUGIN_LOAD(const OBSE::LoadInterface* a_obse)
{
	OBSE::Init(a_obse, { .trampoline = true, .trampolineSize = 32 });
	return true;
}
