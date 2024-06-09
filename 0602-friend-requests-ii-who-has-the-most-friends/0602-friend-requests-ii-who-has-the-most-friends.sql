# Write your MySQL query statement below
with base as 
(
    select requester_id as id
    from RequestAccepted
    
    Union all
    
    select accepter_id as id
    from RequestAccepted
)

select id, count(*) as num
from base
group by id
order by count(*) desc
limit 1