env = Environment()

source = Split("""
        src/exploit/nop_locator.cpp
        src/exploit/local_inject.cpp
        """)

env.SharedLibrary('fury', source)
