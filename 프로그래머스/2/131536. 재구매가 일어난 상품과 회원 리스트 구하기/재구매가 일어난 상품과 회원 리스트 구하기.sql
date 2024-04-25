SELECT USER_ID,PRODUCT_ID
from (
    select user_id,product_id,count(*) as purchase_count
    from online_sale
    group by user_id,product_id
    having purchase_count >=2
)as purchase_count
order by USER_ID asc, PRODUCT_ID desc
# select * from online_sale
# order by user_id
