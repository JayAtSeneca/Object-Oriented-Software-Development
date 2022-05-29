#ifndef SDDS_PROTEINDATABASE_H
#define SDDS_PROTEINDATABASE_H
#include <string>

namespace sdds {

	class ProteinDatabase {
		std::string* m_proteinArr{};
		unsigned int m_size = 0u;
		void safeEmpty();
	public:
		ProteinDatabase();
		ProteinDatabase(const char* fileName);
		ProteinDatabase(const ProteinDatabase& src);
		ProteinDatabase& operator=(const ProteinDatabase& src);
		ProteinDatabase(ProteinDatabase&& src)noexcept;
		ProteinDatabase& operator=(ProteinDatabase&& src)noexcept;
		virtual ~ProteinDatabase();
		unsigned int size()const;
		std::string operator[](unsigned int)const;
	
	};


}
#endif // !SDDS_PROTEINDATABASE_H

