.\\" auto-generated by docbook2man-spec $Revision: 1.25 $
.TH "TRUNCATE" "l" "2003-11-02" "SQL - Language Statements" "SQL Commands"
.SH NAME
TRUNCATE \- empty a table

.SH SYNOPSIS
.sp
.nf
TRUNCATE [ TABLE ] \fIname\fR
.sp
.fi
.SH "DESCRIPTION"
.PP
\fBTRUNCATE\fR quickly removes all rows from a
table. It has the same effect as an unqualified
\fBDELETE\fR but since it does not actually scan the
table it is faster. This is most useful on large tables.
.SH "PARAMETERS"
.TP
\fB\fIname\fB\fR
The name (optionally schema-qualified) of the table to be truncated.
.SH "NOTES"
.PP
\fBTRUNCATE\fR cannot be used if there are foreign-key references
to the table from other tables. Checking validity in such cases would
require table scans, and the whole point is not to do one.
.PP
\fBTRUNCATE\fR will not run any user-defined ON DELETE triggers
that might exist for the table.
.SH "EXAMPLES"
.PP
Truncate the table bigtable:
.sp
.nf
TRUNCATE TABLE bigtable;
.sp
.fi
.SH "COMPATIBILITY"
.PP
There is no \fBTRUNCATE\fR command in the SQL standard.