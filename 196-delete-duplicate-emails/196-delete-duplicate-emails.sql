# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below

delete pe2
from Person pe1 join person pe2 
on pe1.email=pe2.email
and pe1.Id<pe2.Id 