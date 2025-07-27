# Write your MySQL query statement below
SELECT 
ROUND(AVG(subtable.order_date=subtable.customer_pref_delivery_date)*100,2) AS immediate_percentage
FROM (
    SELECT*,ROW_NUMBER() OVER(PARTITION BY customer_id ORDER BY order_date) AS rnk
    FROM delivery
)AS subtable WHERE rnk=1;