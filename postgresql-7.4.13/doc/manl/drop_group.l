.\\" auto-generated by docbook2man-spec $Revision: 1.25 $
.TH "DROP GROUP" "l" "2003-11-02" "SQL - Language Statements" "SQL Commands"
.SH NAME
DROP GROUP \- remove a user group

.SH SYNOPSIS
.sp
.nf
DROP GROUP \fIname\fR
.sp
.fi
.SH "DESCRIPTION"
.PP
\fBDROP GROUP\fR removes the specified group. The
users in the group are not deleted.
.SH "PARAMETERS"
.TP
\fB\fIname\fB\fR
The name of an existing group.
.SH "EXAMPLES"
.PP
To drop a group:
.sp
.nf
DROP GROUP staff;
.sp
.fi
.SH "COMPATIBILITY"
.PP
There is no \fBDROP GROUP\fR statement in the SQL standard.
.SH "SEE ALSO"
ALTER GROUP [\fBalter_group\fR(l)], CREATE GROUP [\fBcreate_group\fR(l)]
