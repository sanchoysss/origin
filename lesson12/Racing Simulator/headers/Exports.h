#ifndef EXPORTS_H
#define EXPORTS_H

#ifdef RACING_LIBRARY_EXPORTS 
#define RACING_API __declspec(dllexport)
#else
#define RACING_API __declspec(dllimport)
#endif
#endif