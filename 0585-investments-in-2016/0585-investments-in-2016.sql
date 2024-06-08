# Write your MySQL query statement below
select ROUND(sum(tiv_2016), 2) as tiv_2016
from Insurance i1
where exists(
    select *
    from Insurance i2
    where i2.pid != i1.pid and 
    i2.tiv_2015 = i1.tiv_2015
) and not exists(
    select *
    from Insurance i2
    where i2.pid != i1.pid and
    i2.lat = i1.lat and i2.lon = i1.lon
)