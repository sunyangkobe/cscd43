insert into student values (0,'Student-A','1988/01/01','Canada','U');
insert into student values (1,'Student-B','1988/06/01','USA','U');
insert into student values (2,'Student-C','1988/12/01','UK','G');
insert into student values (3,'Student-D','1988/12/02','HK','G');

insert into department values (0,'Dept-A','416-123-4567');

insert into program values ('Prog-A', 0);
insert into program values ('Prog-B', 0);

insert into programenroll values (0, 'Prog-A', 2011);
insert into programenroll values (1, 'Prog-B', 2010);
insert into programenroll values (2, 'Prog-A', 2011);
insert into programenroll values (3, 'Prog-A', 2011);

insert into course values(0,'course-A');
insert into course values(1,'course-B');
insert into course values(2,'course-C');
insert into course values(3,'course-D');

insert into courseprogram values(0,'Prog-A');
insert into courseprogram values(1,'Prog-A');
insert into courseprogram values(2,'Prog-B');
insert into courseprogram values(3,'Prog-A');

insert into courseoffer values(0,0,'F',2011);
insert into courseoffer values(1,0,'F',2010);
insert into courseoffer values(2,1,'W',2010);
insert into courseoffer values(3,1,'S',2010);
insert into courseoffer values(4,2,'S',2011);
insert into courseoffer values(5,2,'F',2011);

insert into studentenroll values(0,0,60);
insert into studentenroll values(0,3,20);
insert into studentenroll values(0,5,80);
insert into studentenroll values(1,2,70);
insert into studentenroll values(1,0,70);
insert into studentenroll values(2,1,60);

insert into TAs values(2, 0);
insert into TAs values(3, 0);
insert into TAs values(0, 1);
insert into TAs values(1, 2);
insert into TAs values(2, 3);
insert into TAs values(3, 3);
insert into TAs values(1, 4);
insert into TAs values(2, 5);
insert into TAs values(3, 5);


insert into employee values(0, 'Employee-A','Japan','1370000000',0);
insert into employee values(1, 'Employee-B','China','1380000000',0);
insert into employee values(2, 'Employee-C','Korea','1390000000',0);

insert into researcher values(0,0);
insert into researcher values(1,0);

insert into teacher values(1, 0);
insert into teacher values(1, 1);
insert into teacher values(0, 4);
insert into teacher values(0, 2);
insert into teacher values(2, 3);
insert into teacher values(1, 5);

