#include "Error.h"

Error::Error(const std::string& message) : std::domain_error(message) {};