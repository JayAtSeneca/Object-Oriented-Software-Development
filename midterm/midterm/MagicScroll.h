//MagicScroll.h
#ifndef SDDS_MAGIC_SCROLL_H
#define SDDS_MAGIC_SCROLL_H
namespace sdds {
	enum class Language
	{
		None,        // language not set, spell cannot be used
		OldElf,      // Very potent spell
		ModernHuman, // Regular spell
		Gibberish,   // Not a spell
	};
	class MagicScroll {
		size_t m_length{};
		char* m_incantation{};
		Language m_spell{};
		static int oldElfCount;
	public: 
		MagicScroll();
		MagicScroll(Language scroll, const char* words);
		int getPower();

		// special member functions
		MagicScroll(const MagicScroll& m);
		MagicScroll(MagicScroll&& m);
		MagicScroll& operator=(const MagicScroll& m);
		MagicScroll& operator=(MagicScroll&& m);
		virtual ~MagicScroll();
	};
}
#endif // !SDDS_MAGIC_SCROLL_H
