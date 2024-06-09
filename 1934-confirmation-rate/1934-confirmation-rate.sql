# Write your MySQL query statement below

select user_id, 

    ROUND(
        if(
                ((select count(*) from Confirmations c1 where c1.user_id = s.user_id and c1.action = "confirmed") / 
                 (select count(*) from Confirmations c1 where c1.user_id = s.user_id)) is null, 
            0, 
                ((select count(*) from Confirmations c1 where c1.user_id = s.user_id and c1.action = "confirmed") / 
                 (select count(*) from Confirmations c1 where c1.user_id = s.user_id))
        )
    , 2) as confirmation_rate
from Signups s
group by user_id