# Write your MySQL query statement below
select distinct(customer_id)
from Customer
group by customer_id
having (select count(distinct(product_key)) 
        from Customer c1 
        where c1.customer_id = Customer.customer_id) 
        = (select count(*) from Product)