# Write your MySQL query statement below

select ROUND(count(distinct(a1.player_id)) / (select count(distinct(player_id)) from activity), 2) as fraction
from activity a1
where (a1.player_id, DATE_SUB(a1.event_date, interval 1 day)) IN (
    select a2.player_id, min(a2.event_date)
    from activity a2
    group by player_id
)