#include "local_inject.hpp"

#include <unistd.h>

namespace fury {

void local_inject::inject(const std::string& buffer) const
{
    execl(target_.c_str(), target_.c_str(), buffer.c_str(), (char*) 0);
}

void local_inject::target(const std::string& t)
{
    target_ = t;
}

const std::string& local_inject::target() const
{
    return target_;
}

} // namespace fury
