-- 코드를 입력하세요
SELECT a.product_code as PRODUCT_CODE,sum(a.price*b.sales_amount) as SALES from product as a
join offline_sale as b on a.product_id = b.product_id
group by a.product_code
order by sum(a.price*b.sales_amount) desc, a.product_code asc
