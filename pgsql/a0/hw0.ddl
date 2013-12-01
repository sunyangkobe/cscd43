CREATE TABLE Student (
    sID int not null primary key,
    sName char(20) not null,
    dob date not null,
    address char(20) not null,
    type char(1) not null,
    unique(sName,dob),
    CHECK (type IN ('U','G')));


CREATE TABLE Department (
    deptID int not null primary key,
    deptName char(20) not null,
    phone char(20) not null );


CREATE TABLE Program (
    pName char(20) not null primary key,
    deptID int not null,
    foreign key (deptID) references Department(deptID) ON DELETE CASCADE);


CREATE TABLE ProgramEnroll (
    sID int not null,
    pName char(20) not null,
    year int default 0,
    primary key(sID,pName),
    foreign key (sID) references Student(sID) ON DELETE CASCADE,
    foreign key (pName) references Program(pName) ON DELETE CASCADE);


CREATE TABLE Course (
    cID int not null primary key,
    title char(20) not null);

CREATE TABLE CourseProgram (
    cID int not null,
    pName char(20) not null,
    primary key(cID,pName),
    foreign key (pName) references Program(pName) ON DELETE CASCADE,
    foreign key (cID) references Course(cID) ON DELETE CASCADE);


CREATE TABLE CourseOffer (
    oID int not null primary key,
    cID int not null,
    sem char(1) not null,
    year int default 0,
    foreign key (cID) references Course(cID) ON DELETE CASCADE,
    CHECK (sem IN ('S','F','W'))) WITHOUT oIDs;


CREATE TABLE StudentEnroll (
    sID int not null,
    oID int not null,
    grade int not null,
    primary key(sID , oID),
    foreign key (sID) references Student(sID) ON DELETE CASCADE,
    foreign key (oID) references CourseOffer(oID) ON DELETE CASCADE) without oIDs ;


CREATE TABLE TAs (
    GsID int not null,
    oID int not null,
    primary key(GsID,oID),
    foreign key (GsID) references Student(sID) ON DELETE CASCADE,
    foreign key (oID) references CourseOffer(oID) ON DELETE CASCADE) without oIDs;


CREATE TABLE Employee (
    eID int not null primary key,
    eName char(20) not null,
    address char(20) not null,
    phone char(20) not null,
    deptID int not null,
    foreign key (deptID) references Department(deptID) ON DELETE CASCADE);


CREATE TABLE Researcher (
    rID int not null primary key,
    groupID int not null,
    foreign key (rID) references Employee(eID) ON DELETE CASCADE);


CREATE TABLE Teacher (
    tID int not null,
    oID int not null,
    primary key(tID,oID),
    foreign key (tID) references Employee(eID) ON DELETE CASCADE,
    foreign key (oID) references CourseOffer(oID) ON DELETE CASCADE) without oIDs;




