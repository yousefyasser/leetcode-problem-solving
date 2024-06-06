# Write your MySQL query statement below

select person_name
from Queue q1
where (
    select sum(Weight)
    from Queue
    where turn <= q1.turn  
) <= 1000
order by turn desc
limit 1