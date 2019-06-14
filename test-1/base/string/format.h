#include <utility>

#include "external/tinyformat/tinyformat.h"

template<typename... Args>
inline std::string FormatString(const char* formatString, Args&&... args) {
    return tfm::format(formatString, std::forward<Args>(args)...);
}