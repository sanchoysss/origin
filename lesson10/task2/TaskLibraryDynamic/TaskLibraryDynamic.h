#include <string>

#ifndef TASKLIBRARYDYNAMIC_H
#define TASKLIBRARYDYNAMIC_H

#ifdef TASKLIBRARYDYNAMIC_EXPORTS
#define TASKLIBRARY_API __declspec(dllexport)
#else
#define TASKLIBRARY_API __declspec(dllimport)
#endif 


namespace TaskLibraryDynamic {
	class TASKLIBRARY_API Leaver {
	public:
		std::string leave(const std::string& name);
	};
}

#endif