#ifndef _fury_nop_locator_hpp_
#define _fury_nop_locator_hpp_

#include "types.hpp"

namespace fury {

class nop_locator {
public:
    nop_locator();
    addr_type32 get_addr32() const;
    void sp_offset(long);

private:
    addr_type32 get_sp() const;
    long offset;
};

} // namespace fury

#endif
