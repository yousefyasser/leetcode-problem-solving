# Write your MySQL query statement below
Delete from Person p
where p.id not in (
    select * 
    from (
        select min(id) 
        from Person 
        group by email
    ) as p1
)