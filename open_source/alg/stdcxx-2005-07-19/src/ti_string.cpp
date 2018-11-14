/***************************************************************************
 *
 * ti_string.cpp - explicit instantiation directives for basic_string<char>
 *
 * $Id: //stdlib/dev/source/stdlib/ti_string.cpp#6 $
 *
 ***************************************************************************
 *
 * Copyright (c) 1994-2005 Quovadx,  Inc., acting through its  Rogue Wave
 * Software division. Licensed under the Apache License, Version 2.0 (the
 * "License");  you may  not use this file except  in compliance with the
 * License.    You    may   obtain   a   copy   of    the   License    at
 * http://www.apache.org/licenses/LICENSE-2.0.    Unless   required    by
 * applicable law  or agreed to  in writing,  software  distributed under
 * the License is distributed on an "AS IS" BASIS,  WITHOUT WARRANTIES OR
 * CONDITIONS OF  ANY KIND, either  express or implied.  See  the License
 * for the specific language governing permissions  and limitations under
 * the License.
 * 
 **************************************************************************/

#define _RWSTD_LIB_SRC

#define _RWSTD_INSTANTIATE_TEMPLATES      1
#define _RWSTD_INSTANTIATE_BASIC_STRING   1
#define _RWSTD_INSTANTIATE_CHAR           1

#include <rw/_defs.h>

#undef _RWSTD_NO_TEMPLATE_DEFINITIONS

#include <string>

// verify that the macros are defined in a consistent way:
// when _RWSTD_DEFINE_TEMPLATE() is non-zero, exactly one
// of XXX_FIRST() and XXX_LAST() must be non-zero
// otherwise, when _RWSTD_DEFINE_TEMPLATE() is zero all
// three macros must be zero

#if    _RWSTD_DEFINE_TEMPLATE (_BASIC_STRING) \
    != (  _RWSTD_DEFINE_TEMPLATE_FIRST (_BASIC_STRING) \
        ^ _RWSTD_DEFINE_TEMPLATE_LAST (_BASIC_STRING))
#  error _RWSTD_DEFINE_TEMPLATE definitions inconsistent
#endif
