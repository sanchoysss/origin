#ifndef FIGURE_H
#define FIGURE_H

#include <string>

class  Figure {
protected:
    std::string name;
    Figure(const std::string& figure_name);

public:
    std::string get_name() const;
    virtual void description() const = 0;
    virtual ~Figure() = default;
};

#endif

