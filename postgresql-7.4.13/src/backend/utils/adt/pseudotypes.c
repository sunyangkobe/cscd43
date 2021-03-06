/*-------------------------------------------------------------------------
 *
 * pseudotypes.c
 *	  Functions for the system pseudo-types.
 *
 * A pseudo-type isn't really a type and never has any operations, but
 * we do need to supply input and output functions to satisfy the links
 * in the pseudo-type's entry in pg_type.  In most cases the functions
 * just throw an error if invoked.	(XXX the error messages here cover
 * the most common case, but might be confusing in some contexts.  Can
 * we do better?)
 *
 *
 * Portions Copyright (c) 1996-2003, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 *
 * IDENTIFICATION
 *	  $Header: /cvsroot/pgsql/src/backend/utils/adt/pseudotypes.c,v 1.11 2003/08/04 02:40:05 momjian Exp $
 *
 *-------------------------------------------------------------------------
 */
#include "postgres.h"

#include "libpq/pqformat.h"
#include "utils/array.h"
#include "utils/builtins.h"


/*
 * record_in		- input routine for pseudo-type RECORD.
 */
Datum
record_in(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot accept a value of type record")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}

/*
 * record_out		- output routine for pseudo-type RECORD.
 */
Datum
record_out(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot display a value of type record")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}

/*
 * record_recv		- binary input routine for pseudo-type RECORD.
 */
Datum
record_recv(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot accept a value of type record")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}

/*
 * record_send		- binary output routine for pseudo-type RECORD.
 */
Datum
record_send(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot display a value of type record")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}


/*
 * cstring_in		- input routine for pseudo-type CSTRING.
 *
 * We might as well allow this to support constructs like "foo_in('blah')".
 */
Datum
cstring_in(PG_FUNCTION_ARGS)
{
	char	   *str = PG_GETARG_CSTRING(0);

	PG_RETURN_CSTRING(pstrdup(str));
}

/*
 * cstring_out		- output routine for pseudo-type CSTRING.
 *
 * We allow this mainly so that "SELECT some_output_function(...)" does
 * what the user will expect.
 */
Datum
cstring_out(PG_FUNCTION_ARGS)
{
	char	   *str = PG_GETARG_CSTRING(0);

	PG_RETURN_CSTRING(pstrdup(str));
}

/*
 * cstring_recv		- binary input routine for pseudo-type CSTRING.
 */
Datum
cstring_recv(PG_FUNCTION_ARGS)
{
	StringInfo	buf = (StringInfo) PG_GETARG_POINTER(0);
	char	   *str;
	int			nbytes;

	str = pq_getmsgtext(buf, buf->len - buf->cursor, &nbytes);
	PG_RETURN_CSTRING(str);
}

/*
 * cstring_send		- binary output routine for pseudo-type CSTRING.
 */
Datum
cstring_send(PG_FUNCTION_ARGS)
{
	char	   *str = PG_GETARG_CSTRING(0);
	StringInfoData buf;

	pq_begintypsend(&buf);
	pq_sendtext(&buf, str, strlen(str));
	PG_RETURN_BYTEA_P(pq_endtypsend(&buf));
}


/*
 * any_in		- input routine for pseudo-type ANY.
 */
Datum
any_in(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot accept a value of type any")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}

/*
 * any_out		- output routine for pseudo-type ANY.
 */
Datum
any_out(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot display a value of type any")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}


/*
 * anyarray_in		- input routine for pseudo-type ANYARRAY.
 */
Datum
anyarray_in(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot accept a value of type anyarray")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}

/*
 * anyarray_out		- output routine for pseudo-type ANYARRAY.
 *
 * We may as well allow this, since array_out will in fact work.
 */
Datum
anyarray_out(PG_FUNCTION_ARGS)
{
	return array_out(fcinfo);
}

/*
 * anyarray_recv		- binary input routine for pseudo-type ANYARRAY.
 *
 * XXX this could actually be made to work, since the incoming array
 * data will contain the element type OID.	Need to think through
 * type-safety issues before allowing it, however.
 */
Datum
anyarray_recv(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot accept a value of type anyarray")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}

/*
 * anyarray_send		- binary output routine for pseudo-type ANYARRAY.
 *
 * We may as well allow this, since array_send will in fact work.
 */
Datum
anyarray_send(PG_FUNCTION_ARGS)
{
	return array_send(fcinfo);
}


/*
 * void_in		- input routine for pseudo-type VOID.
 *
 * We allow this so that PL functions can return VOID without any special
 * hack in the PL handler.	Whatever value the PL thinks it's returning
 * will just be ignored.
 */
Datum
void_in(PG_FUNCTION_ARGS)
{
	PG_RETURN_VOID();			/* you were expecting something different? */
}

/*
 * void_out		- output routine for pseudo-type VOID.
 *
 * We allow this so that "SELECT function_returning_void(...)" works.
 */
Datum
void_out(PG_FUNCTION_ARGS)
{
	PG_RETURN_CSTRING(pstrdup(""));
}


/*
 * trigger_in		- input routine for pseudo-type TRIGGER.
 */
Datum
trigger_in(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot accept a value of type trigger")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}

/*
 * trigger_out		- output routine for pseudo-type TRIGGER.
 */
Datum
trigger_out(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot display a value of type trigger")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}


/*
 * language_handler_in		- input routine for pseudo-type LANGUAGE_HANDLER.
 */
Datum
language_handler_in(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot accept a value of type language_handler")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}

/*
 * language_handler_out		- output routine for pseudo-type LANGUAGE_HANDLER.
 */
Datum
language_handler_out(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot display a value of type language_handler")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}


/*
 * internal_in		- input routine for pseudo-type INTERNAL.
 */
Datum
internal_in(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot accept a value of type internal")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}

/*
 * internal_out		- output routine for pseudo-type INTERNAL.
 */
Datum
internal_out(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot display a value of type internal")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}


/*
 * opaque_in		- input routine for pseudo-type OPAQUE.
 */
Datum
opaque_in(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot accept a value of type opaque")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}

/*
 * opaque_out		- output routine for pseudo-type OPAQUE.
 */
Datum
opaque_out(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot display a value of type opaque")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}


/*
 * anyelement_in		- input routine for pseudo-type ANYELEMENT.
 */
Datum
anyelement_in(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot accept a value of type anyelement")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}

/*
 * anyelement_out		- output routine for pseudo-type ANYELEMENT.
 */
Datum
anyelement_out(PG_FUNCTION_ARGS)
{
	ereport(ERROR,
			(errcode(ERRCODE_FEATURE_NOT_SUPPORTED),
			 errmsg("cannot display a value of type anyelement")));

	PG_RETURN_VOID();			/* keep compiler quiet */
}
