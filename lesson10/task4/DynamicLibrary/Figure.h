#ifndef FIGURE_H
#define FIGURE_H

#include <string>

#ifdef DYNAMICLIBRARY_EXPORTS
#define FIGURES_API __declspec(dllexport)
#else
#define FIGURES_API __declspec(dllimport)
#endif 

class FIGURES_API Figure {
protected:
    std::string name;
    Figure(const std::string& figure_name);

public:
    std::string get_name() const;
    virtual void description() const = 0;
    virtual ~Figure() = default;
};

#endif

