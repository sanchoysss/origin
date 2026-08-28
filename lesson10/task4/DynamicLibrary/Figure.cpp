#include "Figure.h"

Figure::Figure(const std::string& figure_name) : name(figure_name) {}

std::string Figure::get_name() const {
    return name;
}

