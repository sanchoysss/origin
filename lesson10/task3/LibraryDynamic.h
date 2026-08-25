#include <string>

#ifndef LIBRARYDYNAMIC_H
#define LIBRARYDYNAMIC_H

#ifdef LIBRARYDYNAMIC_EXPORTS
#define TASKLIBRARY_API __declspec(dllexport)
#else
#define TASKLIBRARY_API __declspec(dllimport)
#endif 


namespace LibraryDynamic {
	class TASKLIBRARY_API Leaver {
	public:
		std::string leave(const std::string& name);
	};
}

#endif