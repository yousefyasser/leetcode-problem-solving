# Write your MySQL query statement below

select 
    ROUND(count(*) * 100 / (select count(distinct(customer_id)) from Delivery), 2) immediate_percentage
from (
    select 
        min(order_date) min_order_date, 
        min(customer_pref_delivery_date) min_delivery_date
    from Delivery
    group by customer_id
    having min_order_date = min_delivery_date
) immediate_deliveries
