/* scd.h
   Copyright (C) 2004 Free Software Foundation, Inc.
 
   This file is part of Poldi.
  
   Poldi is free software; you can redistribute it and/or modify it
   under the terms of the GNU Lesser general Public License as
   published by the Free Software Foundation; either version 2.1 of
   the License, or (at your option) any later version.
  
   Poldi is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
  
   You should have received a copy of the GNU Lesser General Public
   License along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
   02111-1307, USA.  */

#ifndef SCD_H
#define SCD_H

#if 0
#ifdef GPG_ERR_SOURCE_DEFAULT
#error GPG_ERR_SOURCE_DEFAULT already defined
#endif
#define GPG_ERR_SOURCE_DEFAULT  GPG_ERR_SOURCE_USER_1
#endif
#include <gpg-error.h>

#include "../jnlib/xmalloc.h"
#define xfree(a)         free ((a))
#define xtrymalloc(a)    malloc ((a))
#define xtrycalloc(a,b)  calloc ((a),(b))
#define xtryrealloc(a,b) realloc ((a),(b))
#define xtrystrdup(a)    strdup ((a))

#include "../jnlib/logging.h"

#define DBG_COMMAND_VALUE 1	/* debug commands i/o */
#define DBG_MPI_VALUE	  2	/* debug mpi details */
#define DBG_CRYPTO_VALUE  4	/* debug low level crypto */
#define DBG_MEMORY_VALUE  32	/* debug memory allocation stuff */
#define DBG_CACHE_VALUE   64	/* debug the caching */
#define DBG_MEMSTAT_VALUE 128	/* show memory statistics */
#define DBG_HASHING_VALUE 512	/* debug hashing operations */
#define DBG_ASSUAN_VALUE 1024   
#define DBG_CARD_IO_VALUE 2048

#define DBG_COMMAND 0
#define DBG_CRYPTO  0
#define DBG_MEMORY  0
#define DBG_CACHE   0
#define DBG_HASHING 0
#define DBG_ASSUAN  0
#define DBG_CARD_IO 0

struct scd_opt
{
  unsigned int debug; /* debug flags (DBG_foo_VALUE) */
  int debug_sc;     /* OpenSC debug level */
  int verbose;      /* verbosity level */
  const char *ctapi_driver; /* Library to access the ctAPI. */
  const char *pcsc_driver;  /* Library to access the PC/SC system. */
  const char *reader_port;  /* NULL or reder port to use. */
  int disable_opensc;  /* Disable the use of the OpenSC framework. */
  int disable_ccid;    /* Disable the use of the internal CCID driver. */
};

extern struct scd_opt scd_opt;

void scd_init (unsigned int debug, int debug_sc, int verbose,
	       const char *ctapi_driver, const char *pcsc_driver,
	       const char *reader_port, int disable_opensc,
	       int disable_ccid, int debug_ccid_driver);

#define opt scd_opt

#endif /* SCD_H */
