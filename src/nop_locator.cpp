#include "nop_locator.hpp"

namespace fury {

nop_locator::nop_locator() : offset(0)
{
}

void nop_locator::sp_offset(long off)
{
    offset = off;
}

addr_type32 nop_locator::get_addr32() const
{
    return get_sp() + offset;
}

addr_type32 nop_locator::get_sp() const
{
    __asm("movl %esp, %eax");
}


} // namespace fury
