.\\" auto-generated by docbook2man-spec $Revision: 1.25 $
.TH "CREATE CONVERSION" "l" "2003-11-02" "SQL - Language Statements" "SQL Commands"
.SH NAME
CREATE CONVERSION \- define a new conversion

.SH SYNOPSIS
.sp
.nf
CREATE [DEFAULT] CONVERSION \fIname\fR
    FOR \fIsource_encoding\fR TO \fIdest_encoding\fR FROM \fIfuncname\fR
.sp
.fi
.SH "DESCRIPTION"
.PP
\fBCREATE CONVERSION\fR defines a new encoding
conversion. Conversion names may be used in the \fBconvert\fR function
to specify a particular encoding conversion. Also, conversions that
are marked DEFAULT can be used for automatic encoding conversion between
client and server. For this purpose, two conversions, from encoding A to
B \fBand\fR from encoding B to A, must be defined.
.PP
To be able to create a conversion, you must have EXECUTE privilege
on the function and CREATE privilege on the destination schema.
.SH "PARAMETERS"
.TP
\fBDEFAULT\fR
The DEFAULT clause indicates that this conversion
is the default for this particular source to destination
encoding. There should be only one default encoding in a schema
for the encoding pair.
.TP
\fB\fIname\fB\fR
The name of the conversion. The conversion name may be
schema-qualified. If it is not, the conversion is defined in the
current schema. The conversion name must be unique within a
schema.
.TP
\fB\fIsource_encoding\fB\fR
The source encoding name.
.TP
\fB\fIdest_encoding\fB\fR
The destination encoding name.
.TP
\fB\fIfuncname\fB\fR
The function used to perform the conversion. The function name may
be schema-qualified. If it is not, the function will be looked
up in the path.

The function must have the following signature:
.sp
.nf
conv_proc(
    integer,  -- source encoding ID
    integer,  -- destination encoding ID
    cstring,  -- source string (null terminated C string)
    cstring,  -- destination string (null terminated C string)
    integer   -- source string length
) RETURNS void;
.sp
.fi
.SH "NOTES"
.PP
Use \fBDROP CONVERSION\fR to remove user-defined conversions.
.PP
The privileges required to create a conversion may be changed in a future
release.
.SH "EXAMPLES"
.PP
To create a conversion from encoding UNICODE to
LATIN1 using \fBmyfunc\fR:
.sp
.nf
CREATE CONVERSION myconv FOR 'UNICODE' TO 'LATIN1' FROM myfunc;
.sp
.fi
.SH "COMPATIBILITY"
.PP
\fBCREATE CONVERSION\fR
is a PostgreSQL extension.
There is no \fBCREATE CONVERSION\fR
statement in the SQL standard.
.SH "SEE ALSO"
ALTER CONVERSION [\fBalter_conversion\fR(l)], CREATE FUNCTION [\fBcreate_function\fR(l)], DROP CONVERSION [\fBdrop_conversion\fR(l)]
