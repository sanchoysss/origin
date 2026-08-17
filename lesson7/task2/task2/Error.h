#ifndef ERROR_H
#define ERROR_H

#include <stdexcept>
#include <string>

class Error : public std::domain_error {
public:
	explicit Error(const std::string& message);
};
#endif