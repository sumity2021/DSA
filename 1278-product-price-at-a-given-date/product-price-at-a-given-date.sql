# Write your MySQL query statement below
SELECT product_id,10 AS price FROM products WHERE product_id not in 
(
    SELECT product_id FROM products WHERE change_date<='2019-08-16'
)
UNION
SELECT product_id , new_price AS price FROM products WHERE (product_id,change_date) in
(
    SELECT product_id , max(change_date) FROM products WHERE change_date<='2019-08-16' GROUP BY product_id
)