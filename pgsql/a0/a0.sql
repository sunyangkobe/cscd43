--Shuang Jiang
--996022281
--Assignment 0

--1
SELECT course.title 
FROM course 
JOIN
	(SELECT cid 
	FROM programenroll 
	JOIN courseprogram 
	ON programenroll.pname = courseprogram.pname 
	WHERE sid = 0) AS A 
ON course.cid = A.cid;

--2
SELECT ename 
FROM employee 
JOIN
  (SELECT DISTINCT tid 
  FROM teacher 
  JOIN 
    (SELECT studentenroll.oid 
	FROM studentenroll 
	JOIN courseoffer 
	ON studentenroll.oid = courseoffer.oid 
	WHERE courseoffer.sem = 'F' AND year = 2011) AS A 
  ON teacher.oid = A.oid) AS B 
ON employee.eid = B.tid;

--3
SELECT ename 
FROM employee 
JOIN
  (SELECT eid 
  FROM employee 
  EXCEPT 
    (SELECT DISTINCT tid 
    FROM teacher 
    JOIN 
      (SELECT courseoffer.oid 
      FROM courseoffer 
      JOIN 
        (SELECT oid 
        FROM studentenroll 
        WHERE grade > 50) AS A 
      ON courseoffer.oid = A.oid 
      WHERE sem = 'F') AS B 
    ON teacher.oid = B.oid)) AS C 
ON employee.eid = C.eid;

--4
CREATE VIEW q1 AS SELECT oid FROM studentenroll WHERE sid = 0;
CREATE VIEW q2 AS SELECT DISTINCT gsid FROM tas JOIN q1 ON tas.oid = q1.oid;
CREATE VIEW q3 AS SELECT gsid,oid FROM q1,q2;
CREATE VIEW q4 AS SELECT tas.gsid,oid FROM tas JOIN q2 ON tas.gsid = q2.gsid;
CREATE VIEW q5 AS (SELECT * FROM q3 EXCEPT SELECT * FROM q4);
CREATE VIEW q6 AS (SELECT DISTINCT gsid FROM q3 EXCEPT SELECT DISTINCT gsid FROM q5);

SELECT sName FROM student JOIN q6 ON student.sid = q6.gsid WHERE type = 'G';
DROP VIEW q6,q5,q4,q3,q2,q1;

--Alternate solution
--SELECT sname FROM student JOIN (SELECT gsid,COUNT(gsid) FROM TAs JOIN (SELECT oid FROM studentenroll WHERE sid = 0) AS A ON tas.oid = A.oid GROUP BY gsid HAVING COUNT(gsid) = (SELECT COUNT(oid) FROM studentenroll WHERE sid = 0)) AS B ON student.sid = B.gsid WHERE student.type = 'G';
