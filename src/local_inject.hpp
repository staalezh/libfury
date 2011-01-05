#ifndef _fury_local_inject_hpp_
#define _fury_local_inject_hpp_

#include <string>

namespace fury {

class local_inject {
public:
    void inject(const std::string&) const;

    void target(const std::string&);
    const std::string& target() const;

private:
    std::string target_;
};

} // namespace fury

#endif
