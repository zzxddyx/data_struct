// checking for bad_cast::what()

#if defined (_RWSTD_USE_CONFIG)
#  include "config.h"
#endif


#ifndef _RWSTD_NO_HONOR_STD
#  ifdef _RWSTD_NO_STD_TERMINATE

namespace std {

void terminate ()
{
    static int *ip;

    *ip++ = 0;      // force a SIGSEGV
    terminate ();   // recurse infinitely
}

}

#  endif   // _RWSTD_NO_STD_TERMINATE
#endif   // _RWSTD_NO_HONOR_STD


#ifndef _RWSTD_NO_STD_BAD_CAST
#  define NAMESPACE(name)   namespace name
#else
#  ifndef _RWSTD_NO_GLOBAL_BAD_CAST
#    define NAMESPACE(ignore)   extern "C++"
#    define std                 /* empty */
#  else
#    ifndef _RWSTD_NO_RUNTIME_IN_STD
#      define NAMESPACE(name)   namespace name
#    else
#      define NAMESPACE(ignore)   extern "C++"
#      define std                 /* empty */
#    endif   // _RWSTD_NO_RUNTIME_IN_STD
#  endif   // _RWSTD_NO_GLOBAL_BAD_CAST
#endif   // _RWSTD_NO_STD_BAD_CAST


NAMESPACE (std) {

class bad_cast
{
public:

#ifndef _RWSTD_NO_BAD_CAST_DEFAULT_CTOR

    bad_cast ();

#else

    bad_cast () { }

#endif   // _RWSTD_NO_BAD_CAST_DEFAULT_CTOR

#ifndef _RWSTD_NO_BAD_CAST_DTOR

    virtual ~bad_cast ();

#else

    virtual ~bad_cast () { }

#endif   // _RWSTD_NO_BAD_CAST_DEFAULT_CTOR

    virtual const char* what () const;
};

}   // namespace std


int main (int argc, char *argv[])
{
    // prevent foo from actually being called but do it so that
    // the optimizer can't actually figure it out and eliminate
    // the function
    if (argc > 256) {
	std::bad_cast bc;

	return !bc.what ();
    }

    // link only test
    return 0;
}
