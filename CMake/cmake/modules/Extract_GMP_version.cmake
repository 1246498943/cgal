include(ReadLines)
include(FindMatchingItem)
  
if ( GMP_FOUND )

  readlines(${GMP_INCLUDE_DIR}/gmp.h GMP_H_FILE)

  find_matching_item(GMP_H_FILE "__GNU_MP_VERSION "            __GNU_MP_VERSION_LINE )
  find_matching_item(GMP_H_FILE "__GNU_MP_VERSION_MINOR "      __GNU_MP_VERSION_MINOR_LINE )
  find_matching_item(GMP_H_FILE "__GNU_MP_VERSION_PATCHLEVEL " __GNU_MP_VERSION_PATCHLEVEL_LINE )
  
  string( REPLACE " " ";" __GNU_MP_VERSION_LINE_LIST            ${__GNU_MP_VERSION_LINE}            )
  string( REPLACE " " ";" __GNU_MP_VERSION_MINOR_LINE_LIST      ${__GNU_MP_VERSION_MINOR_LINE}      )
  string( REPLACE " " ";" __GNU_MP_VERSION_PATCHLEVEL_LINE_LIST ${__GNU_MP_VERSION_PATCHLEVEL_LINE} )
  
  list( GET __GNU_MP_VERSION_LINE_LIST            2 __GNU_MP_VERSION )
  list( GET __GNU_MP_VERSION_MINOR_LINE_LIST      2 __GNU_MP_VERSION_MINOR )
  list( GET __GNU_MP_VERSION_PATCHLEVEL_LINE_LIST 2 __GNU_MP_VERSION_PATCHLEVEL )
  
  set( GMP_VERSION "${__GNU_MP_VERSION}.${__GNU_MP_VERSION_MINOR}.${__GNU_MP_VERSION_PATCHLEVEL}" )
  
  message( STATUS "USING GMP_VERSION = '${GMP_VERSION}'" )
  
endif()

if ( GMPXX_FOUND AND GMP_VERSION )

  set( GMPXX_VERSION ${GMP_VERSION} )
  
  message( STATUS "USING GMPXX_VERSION = '${GMPXX_VERSION}'" )
  
endif()
