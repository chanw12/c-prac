-- 코드를 입력하세요
SELECT c.AUTHOR_ID as AUTHOR_ID,c.AUTHOR_NAME as AUTHOR_NAME,c.CATEGORY as CATEGORY,sum(bs.sales * c.price) as TOTAL_SALES  from book_sales as bs
join (
    select a.author_id,a.author_name,b.category,b.price,b.book_id from author as a
    join book as b on b.author_id = a.author_id
) as c on c.book_id = bs.book_id
where year(sales_date) = 2022 and month(sales_date) = 1
group by c.author_id , c.category
order by 1,3 desc