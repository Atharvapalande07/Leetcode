# Write your MySQL query statement below
select w1.id 
from Weather w1
join Weather w2
on w1.temperature > w2.temperature
and DATEDIFF(w1.recordDAte , w2.recordDate)=1;

